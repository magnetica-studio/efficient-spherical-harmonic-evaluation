#include <array>
#include <cmath>
#include <numeric>
#include <tuple>
#include <utility>
#include <variant>

namespace novonotes::constexprsheval
{
constexpr double PI = 3.1415926535897932384626433832795;

template <int M>
constexpr int constabs()
{
    if constexpr(M < 0)
    {
        return -M;
    }
    else
    {
        return M;
    }
}

constexpr double constsqrt(double s)
{
    double x = s / 2.0;
    double prev = 0.0;

    while(x != prev)
    {
        prev = x;
        x = (x + s / x) / 2.0;
    }
    return x;
}

constexpr double K(unsigned int l, int m)
{
    unsigned int cABSM = m < 0 ? -m : m;

    double uVal = 1;  // has to be double or code is incorrect for large m starting
                      // around order 8...

    for(unsigned int k = l + cABSM; k > (l - cABSM); k--)
    {
        uVal *= k;
    }

    return constsqrt((2.0 * l + 1.0) / (4 * PI * uVal));
}

constexpr double Pmm(int m)
{
    double val = 1.0;

    for(int k = 0; k <= m; k++)
    {
        val = val * (1 - 2 * k);
    }

    return val;
};

struct RuleAObj
{
    constexpr RuleAObj() {}
    explicit constexpr RuleAObj(int m, double fval)
    {
        fA = double(Pmm(m) * K(m, m) * fval);
    }
    constexpr double operator()(double z) const { return fA; }
    double fA = 0;
};

// Pmm = (1-2m) Pm-1m-1 => prod_k(1-2k)

// Pmm+1 = (2m+1) z Pmm => constant times z
struct RuleBObj
{
    constexpr RuleBObj() {}
    explicit constexpr RuleBObj(int m, double fval)
    {
        fA = double((2 * m + 1.0) * Pmm(m) * K(m + 1, m) * fval);
    }
    constexpr double operator()(double z) const { return fA * z; }
    double fA = 0;
};

// plug rule A and B into rule C
// Pmm+2 = ( (2(m+2)-1) z ((2m+1) z Pmm) - (m+2+m-1) Pmm  )/2
// now fold all of the constants together...
// Pmm+2 = ( (2m+3)(2m+1)Pmm/2 z^2  - (2m+1) Pmm / 2

struct RuleDObj
{
    constexpr RuleDObj() {}
    explicit constexpr RuleDObj(int m, double fval)
    {
        const int l = m + 2;

        fA = double((2 * m + 3) * (2 * m + 1) * Pmm(m) / 2 * K(l, m) * fval);
        fB = double(-1.0 * (2 * m + 1) * Pmm(m) / 2 * K(l, m) * fval);
    }
    constexpr double operator()(double z) const { return fA * (z * z) + fB; }
    double fA = 0, fB = 0;
};
// plug rule D and B into rule C, factor out a z...
// Pmm+3 = ( (2(m+3)-1)z (( (2m+3)(2m+1)Pmm/2 z^2  - (2m+1) Pmm / 2) - (m+3+m-1)
// (2m+1) z Pmm )/3 fold constants, pull out z... Pmm+3 = z (
// (2m+5)(2m+3)(2m+1)Pmm/6 z^2 - ( (2m+5)(2m+1) Pmm/6 + (2m+2)(2m+1) Pmm/3 )

struct RuleEObj
{
    constexpr RuleEObj() {}
    explicit constexpr RuleEObj(int m, double fval)
    {
        const int l = m + 3;
        const double Pu = Pmm(m);
        fA = (2 * m + 5) * (2 * m + 3) * (2 * m + 1) * Pu / 6 * K(m + 3, m) * fval;
        fB = -fval * K(m + 3, m) *
             ((2 * m + 5) * (2 * m + 1) * Pu / 6 +
              (2 * m + 2) * (2 * m + 1) * Pu / 3);
    }
    constexpr double operator()(double z, double zz) const
    {
        return z * (fA * (zz) + fB);
    }
    double fA = 0, fB = 0;
};

// PmL = ((2L-1)z PmL-1 - (L+m-1) PmL-2)/(L-m)
// workhorse rule, other rules are modeled as special cases of this rule...
// PmL = ((2L-1)/ (L-m) PmL-1  z - (L+m-1)/ (L-m) PmL-2
// assume Klm and fVal were folded into previous values...
// fVal not neded - since it is included in PmL-1 and PmL-2 already...
struct RuleCObj
{
    constexpr RuleCObj() {}
    explicit constexpr RuleCObj(int l, int m)
        : fA(K(l, m) / K(l - 1, m) * (2 * l - 1.0) / (l - m))
        , fB(-K(l, m) / K(l - 2, m) * (l + m - 1.0) / (l - m)) {}
    constexpr double operator()(double Pm1, double Pm2, double z) const
    {
        return fA * z * Pm1 + fB * Pm2;
    }

    double fA = 0;
    double fB = 1;
};

// this is the reccurence relation for sin/cos

constexpr double SinReccur(double sCL, double sSL, double x, double y)
{
    return x * sSL + y * sCL;
}

constexpr double CosReccur(double sCL, double sSL, double x, double y)
{
    return x * sCL - y * sSL;
}

template <int ORDER>
constexpr auto getRuleAList()
{
    std::array<RuleAObj, ORDER> res;
    int m = 0;
    for(int m = 0; m < ORDER; m++)
    {
        res.at(m) = RuleAObj(m+1, constsqrt(2.0));
    }
    return res;
}

template <int ORDER>
constexpr auto getRuleBList()
{
    std::array<RuleBObj, ORDER> res;
    int m = 0;
    for(int m = 0; m < ORDER; m++)
    {
        res.at(m) = RuleBObj(m+1, constsqrt(2.0));
    }
    return res;
}

template <int ORDER>
constexpr auto getRuleDList()
{
    std::array<RuleDObj, ORDER> res{};
    int m = 0;
    for(int m = 0; m < ORDER; m++)
    {
        res.at(m) = RuleDObj(m+1, constsqrt(2.0));
    }
    return res;
}
template <int ORDER>
constexpr auto getRuleEList()
{
    std::array<RuleEObj, ORDER> res;
    int m = 0;
    for(int m = 0; m < ORDER; m++)
    {
        res.at(m) = RuleEObj(m+1, constsqrt(2.0));
    }
    return res;
}

// constexpr matrix that generates function for l0,m0 l
// maybe not all combination are used but,,,
template <int L, int M>
constexpr auto getRuleCMatrix()
{
    std::array<std::array<RuleCObj, L>, M> res{};
    int m = 0;
    int l = 0;

    for(int m = 0; m < M; m++)
    {
        for(int l = 0; l < L; l++)
        {
            if(l+4  - m != 0)
            {
                res.at(m).at(l) = RuleCObj(l+4, m);
            }
        }
    }

    return res;
}

using shevalfntype = double (*)(double, double, double);

constexpr int getlen(int order)
{
    int res = 0;
    for(int i = 0; i <= order; i++)
    {
        res += 2 * i + 1;
    }

    return res;
}

template <int ORDER>
auto SHEvalExec(double x, double y, double z)
    -> std::array<double, getlen(ORDER)>
{
    constexpr int matlen = getlen(ORDER);
    constexpr auto alist = getRuleAList<ORDER-1>();
    constexpr auto blist = getRuleBList<ORDER-2>();
    constexpr auto dlist = getRuleDList<ORDER-3>();
    constexpr auto elist = getRuleEList<ORDER-4>();
    constexpr auto cmatrix = getRuleCMatrix<ORDER-3, ORDER>();
    double zz = z * z;
    std::array<double, getlen(ORDER)> res;
    constexpr auto zeroth = K(0, 0);
    res[0] = zeroth;
    if constexpr(matlen == 0)
        return res;
    constexpr int mc = 0;
    int l = 1;
    int idx = l * l + l;
    if constexpr(ORDER > 1)
    {
        constexpr auto b = RuleBObj(mc, 1.0);
        res[idx] = b(z);
    }
    if constexpr(ORDER > 2)
    {
        l = 2;
        idx = l * l + l;
        constexpr auto d = RuleDObj(mc, 1.0);
        res[idx] = d(z);
    }
    if constexpr(ORDER > 3)
    {
        l = 3;
        idx = l * l + l;
        constexpr auto e = RuleEObj(mc, 1.0);
        res[idx] = e(z, zz);
    }
    if constexpr(ORDER > 4)
    {
        for(l = 4; l <= ORDER; l++)
        {
            auto Pm1 = res[(l - 1) * (l - 1) + (l - 1)];
            auto Pm2 = res[(l - 2) * (l - 2) + (l - 2)];
            idx = l * l + l;
            auto&& c = cmatrix.at(mc).at(l-4);
            res[idx] = c(Pm1, Pm2, z);
        }
    }
    double fC0, fC1, fS0, fS1, fTmpA, fTmpB, fTmpC;
    std::array<double, 3> fprev{0, 0, 0};
    std::array<double, 2> fc{x, 0};
    std::array<double, 2> fs{y, 0};

    double fZ2 = z * z;
    int idxC, idxS,
        idxP;  // cosine (+m) sine (-m) pairs are what you loop through...
    bool sincos_flip = false;
    int m = 1;
    for(m = 1; m < ORDER; m++)
    {
        l = m;
        for(int iter = 0; iter < 4; iter++)  // calc a,b,d,e first
        {
            idxP++;

            if(m + iter <= ORDER)
            {
                idxC = l * l + l + m;
                idxS = l * l + l - m;

                switch(iter)
                {
                    case 0:
                        fprev[idxP % 3] = alist[m-1](z);
                        break;
                    case 1:
                        fprev[idxP % 3] = blist[m-1](z);
                        break;
                    case 2:
                        fprev[idxP % 3] = dlist[m-1](z);
                        break;
                    case 3:
                        fprev[idxP % 3] = elist[m-1](z, zz);
                        break;
                    default:
                        break;
                }
                res[idxC] = fprev[idxP % 3] * fc[(int)sincos_flip];
                res[idxS] = fprev[idxP % 3] * fs[(int)sincos_flip];
                l++;
            }
        }

        for(l = m + 4; l <= ORDER; l++)
        {  // then, calc other coeffs using ruleC
            idxC = l * l + l + m;
            idxS = l * l + l - m;

            auto&& c = cmatrix.at(m).at(l-4);
            idxP++;
            fprev[idxP % 3] =
                c(fprev[(idxP + 3 - 1) % 3], fprev[(idxP + 3 - 2) % 3], z);
            res[idxC] = fprev[idxP % 3] * fc[(int)sincos_flip];
            res[idxS] = fprev[idxP % 3] * fs[(int)sincos_flip];
        }

        // update cosine and sine
        fc[(int)!sincos_flip] =
            CosReccur(fc[(int)sincos_flip], fs[(int)sincos_flip], x, y);
        fs[(int)!sincos_flip] =
            SinReccur(fc[(int)sincos_flip], fs[(int)sincos_flip], x, y);

        sincos_flip = !sincos_flip;
    }
    // final pair

    l = ORDER;

    idxC = l * l + l + ORDER;
    idxS = l * l + l - ORDER;

    idxP = (idxP + 1) % 3;  // use any tmp variable here, just bump to the next to
                            // maximize scheduling issues...
    constexpr auto atmp = RuleAObj(ORDER, constsqrt(2.0));
    fprev[idxP] = atmp(z);

    res[idxC] = fprev[idxP] * fc[(int)sincos_flip];
    res[idxS] = fprev[idxP] * fs[(int)sincos_flip];

    return res;
}
}  // namespace novonotes::constexprsheval