// Generated by rstantools.  Do not edit by hand.

/*
    BayesSenMC is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    BayesSenMC is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with BayesSenMC.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.21.0
#include <stan/model/model_header.hpp>
namespace model_fixedCorr_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_fixedCorr");
    reader.add_event(51, 49, "end", "model_fixedCorr");
    return reader;
}
#include <stan_meta_header.hpp>
class model_fixedCorr
  : public stan::model::model_base_crtp<model_fixedCorr> {
private:
        int a;
        int N1;
        int c;
        int N0;
        double mX0;
        double precX0;
        double mX1;
        double precX1;
        double rhoSe;
        double mLogit_pi0;
        double sLogit_pi0;
        double mLOR_c;
        double sLOR_c;
public:
    model_fixedCorr(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_fixedCorr(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_fixedCorr_namespace::model_fixedCorr";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 2;
            context__.validate_dims("data initialization", "a", "int", context__.to_vec());
            a = int(0);
            vals_i__ = context__.vals_i("a");
            pos__ = 0;
            a = vals_i__[pos__++];
            check_greater_or_equal(function__, "a", a, 0);
            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "N1", "int", context__.to_vec());
            N1 = int(0);
            vals_i__ = context__.vals_i("N1");
            pos__ = 0;
            N1 = vals_i__[pos__++];
            check_greater_or_equal(function__, "N1", N1, 0);
            current_statement_begin__ = 4;
            context__.validate_dims("data initialization", "c", "int", context__.to_vec());
            c = int(0);
            vals_i__ = context__.vals_i("c");
            pos__ = 0;
            c = vals_i__[pos__++];
            check_greater_or_equal(function__, "c", c, 0);
            current_statement_begin__ = 5;
            context__.validate_dims("data initialization", "N0", "int", context__.to_vec());
            N0 = int(0);
            vals_i__ = context__.vals_i("N0");
            pos__ = 0;
            N0 = vals_i__[pos__++];
            check_greater_or_equal(function__, "N0", N0, 0);
            current_statement_begin__ = 6;
            context__.validate_dims("data initialization", "mX0", "double", context__.to_vec());
            mX0 = double(0);
            vals_r__ = context__.vals_r("mX0");
            pos__ = 0;
            mX0 = vals_r__[pos__++];
            current_statement_begin__ = 7;
            context__.validate_dims("data initialization", "precX0", "double", context__.to_vec());
            precX0 = double(0);
            vals_r__ = context__.vals_r("precX0");
            pos__ = 0;
            precX0 = vals_r__[pos__++];
            current_statement_begin__ = 8;
            context__.validate_dims("data initialization", "mX1", "double", context__.to_vec());
            mX1 = double(0);
            vals_r__ = context__.vals_r("mX1");
            pos__ = 0;
            mX1 = vals_r__[pos__++];
            current_statement_begin__ = 9;
            context__.validate_dims("data initialization", "precX1", "double", context__.to_vec());
            precX1 = double(0);
            vals_r__ = context__.vals_r("precX1");
            pos__ = 0;
            precX1 = vals_r__[pos__++];
            current_statement_begin__ = 10;
            context__.validate_dims("data initialization", "rhoSe", "double", context__.to_vec());
            rhoSe = double(0);
            vals_r__ = context__.vals_r("rhoSe");
            pos__ = 0;
            rhoSe = vals_r__[pos__++];
            current_statement_begin__ = 11;
            context__.validate_dims("data initialization", "mLogit_pi0", "double", context__.to_vec());
            mLogit_pi0 = double(0);
            vals_r__ = context__.vals_r("mLogit_pi0");
            pos__ = 0;
            mLogit_pi0 = vals_r__[pos__++];
            current_statement_begin__ = 12;
            context__.validate_dims("data initialization", "sLogit_pi0", "double", context__.to_vec());
            sLogit_pi0 = double(0);
            vals_r__ = context__.vals_r("sLogit_pi0");
            pos__ = 0;
            sLogit_pi0 = vals_r__[pos__++];
            check_greater_or_equal(function__, "sLogit_pi0", sLogit_pi0, 0);
            current_statement_begin__ = 13;
            context__.validate_dims("data initialization", "mLOR_c", "double", context__.to_vec());
            mLOR_c = double(0);
            vals_r__ = context__.vals_r("mLOR_c");
            pos__ = 0;
            mLOR_c = vals_r__[pos__++];
            current_statement_begin__ = 14;
            context__.validate_dims("data initialization", "sLOR_c", "double", context__.to_vec());
            sLOR_c = double(0);
            vals_r__ = context__.vals_r("sLOR_c");
            pos__ = 0;
            sLOR_c = vals_r__[pos__++];
            check_greater_or_equal(function__, "sLOR_c", sLOR_c, 0);
            // initialize transformed data variables
            // execute transformed data statements
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 17;
            num_params_r__ += 1;
            current_statement_begin__ = 18;
            num_params_r__ += 1;
            current_statement_begin__ = 19;
            num_params_r__ += 1;
            current_statement_begin__ = 20;
            num_params_r__ += 1;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_fixedCorr() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 17;
        if (!(context__.contains_r("logit_pi0")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable logit_pi0 missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("logit_pi0");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "logit_pi0", "double", context__.to_vec());
        double logit_pi0(0);
        logit_pi0 = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(logit_pi0);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable logit_pi0: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 18;
        if (!(context__.contains_r("LOR_c")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable LOR_c missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("LOR_c");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "LOR_c", "double", context__.to_vec());
        double LOR_c(0);
        LOR_c = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(LOR_c);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable LOR_c: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 19;
        if (!(context__.contains_r("X0")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable X0 missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("X0");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "X0", "double", context__.to_vec());
        double X0(0);
        X0 = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(X0);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable X0: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 20;
        if (!(context__.contains_r("X1")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable X1 missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("X1");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "X1", "double", context__.to_vec());
        double X1(0);
        X1 = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(X1);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable X1: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 17;
            local_scalar_t__ logit_pi0;
            (void) logit_pi0;  // dummy to suppress unused var warning
            if (jacobian__)
                logit_pi0 = in__.scalar_constrain(lp__);
            else
                logit_pi0 = in__.scalar_constrain();
            current_statement_begin__ = 18;
            local_scalar_t__ LOR_c;
            (void) LOR_c;  // dummy to suppress unused var warning
            if (jacobian__)
                LOR_c = in__.scalar_constrain(lp__);
            else
                LOR_c = in__.scalar_constrain();
            current_statement_begin__ = 19;
            local_scalar_t__ X0;
            (void) X0;  // dummy to suppress unused var warning
            if (jacobian__)
                X0 = in__.scalar_constrain(lp__);
            else
                X0 = in__.scalar_constrain();
            current_statement_begin__ = 20;
            local_scalar_t__ X1;
            (void) X1;  // dummy to suppress unused var warning
            if (jacobian__)
                X1 = in__.scalar_constrain(lp__);
            else
                X1 = in__.scalar_constrain();
            // transformed parameters
            current_statement_begin__ = 23;
            local_scalar_t__ pi1;
            (void) pi1;  // dummy to suppress unused var warning
            stan::math::initialize(pi1, DUMMY_VAR__);
            stan::math::fill(pi1, DUMMY_VAR__);
            current_statement_begin__ = 24;
            local_scalar_t__ pi0;
            (void) pi0;  // dummy to suppress unused var warning
            stan::math::initialize(pi0, DUMMY_VAR__);
            stan::math::fill(pi0, DUMMY_VAR__);
            current_statement_begin__ = 25;
            local_scalar_t__ ORadj;
            (void) ORadj;  // dummy to suppress unused var warning
            stan::math::initialize(ORadj, DUMMY_VAR__);
            stan::math::fill(ORadj, DUMMY_VAR__);
            current_statement_begin__ = 26;
            local_scalar_t__ Se;
            (void) Se;  // dummy to suppress unused var warning
            stan::math::initialize(Se, DUMMY_VAR__);
            stan::math::fill(Se, DUMMY_VAR__);
            current_statement_begin__ = 27;
            local_scalar_t__ Sp;
            (void) Sp;  // dummy to suppress unused var warning
            stan::math::initialize(Sp, DUMMY_VAR__);
            stan::math::fill(Sp, DUMMY_VAR__);
            current_statement_begin__ = 28;
            local_scalar_t__ mcx1;
            (void) mcx1;  // dummy to suppress unused var warning
            stan::math::initialize(mcx1, DUMMY_VAR__);
            stan::math::fill(mcx1, DUMMY_VAR__);
            current_statement_begin__ = 29;
            local_scalar_t__ preccx1;
            (void) preccx1;  // dummy to suppress unused var warning
            stan::math::initialize(preccx1, DUMMY_VAR__);
            stan::math::fill(preccx1, DUMMY_VAR__);
            current_statement_begin__ = 30;
            local_scalar_t__ p1;
            (void) p1;  // dummy to suppress unused var warning
            stan::math::initialize(p1, DUMMY_VAR__);
            stan::math::fill(p1, DUMMY_VAR__);
            current_statement_begin__ = 31;
            local_scalar_t__ p0;
            (void) p0;  // dummy to suppress unused var warning
            stan::math::initialize(p0, DUMMY_VAR__);
            stan::math::fill(p0, DUMMY_VAR__);
            // transformed parameters block statements
            current_statement_begin__ = 32;
            stan::math::assign(mcx1, (mX1 + ((rhoSe * (X0 - mX0)) * pow((precX1 / precX0), 0.5))));
            current_statement_begin__ = 33;
            stan::math::assign(preccx1, (precX1 / (1 - pow(rhoSe, 2))));
            current_statement_begin__ = 34;
            stan::math::assign(pi0, (stan::math::exp(logit_pi0) / (stan::math::exp(logit_pi0) + 1)));
            current_statement_begin__ = 35;
            stan::math::assign(pi1, (stan::math::exp((logit_pi0 + LOR_c)) / (stan::math::exp((logit_pi0 + LOR_c)) + 1)));
            current_statement_begin__ = 36;
            stan::math::assign(Se, ((1 + (stan::math::exp(X0) / (1 + stan::math::exp(X0)))) / 2));
            current_statement_begin__ = 37;
            stan::math::assign(Sp, ((1 + (stan::math::exp(X1) / (1 + stan::math::exp(X1)))) / 2));
            current_statement_begin__ = 38;
            stan::math::assign(p1, ((pi1 * Se) + ((1 - pi1) * (1 - Sp))));
            current_statement_begin__ = 39;
            stan::math::assign(p0, ((pi0 * Se) + ((1 - pi0) * (1 - Sp))));
            current_statement_begin__ = 40;
            stan::math::assign(ORadj, stan::math::exp(LOR_c));
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 23;
            if (stan::math::is_uninitialized(pi1)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: pi1";
                stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable pi1: ") + msg__.str()), current_statement_begin__, prog_reader__());
            }
            check_greater_or_equal(function__, "pi1", pi1, 0);
            check_less_or_equal(function__, "pi1", pi1, 1);
            current_statement_begin__ = 24;
            if (stan::math::is_uninitialized(pi0)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: pi0";
                stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable pi0: ") + msg__.str()), current_statement_begin__, prog_reader__());
            }
            check_greater_or_equal(function__, "pi0", pi0, 0);
            check_less_or_equal(function__, "pi0", pi0, 1);
            current_statement_begin__ = 25;
            if (stan::math::is_uninitialized(ORadj)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: ORadj";
                stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable ORadj: ") + msg__.str()), current_statement_begin__, prog_reader__());
            }
            current_statement_begin__ = 26;
            if (stan::math::is_uninitialized(Se)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: Se";
                stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable Se: ") + msg__.str()), current_statement_begin__, prog_reader__());
            }
            check_greater_or_equal(function__, "Se", Se, 0);
            check_less_or_equal(function__, "Se", Se, 1);
            current_statement_begin__ = 27;
            if (stan::math::is_uninitialized(Sp)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: Sp";
                stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable Sp: ") + msg__.str()), current_statement_begin__, prog_reader__());
            }
            check_greater_or_equal(function__, "Sp", Sp, 0);
            check_less_or_equal(function__, "Sp", Sp, 1);
            current_statement_begin__ = 28;
            if (stan::math::is_uninitialized(mcx1)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: mcx1";
                stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable mcx1: ") + msg__.str()), current_statement_begin__, prog_reader__());
            }
            current_statement_begin__ = 29;
            if (stan::math::is_uninitialized(preccx1)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: preccx1";
                stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable preccx1: ") + msg__.str()), current_statement_begin__, prog_reader__());
            }
            current_statement_begin__ = 30;
            if (stan::math::is_uninitialized(p1)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: p1";
                stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable p1: ") + msg__.str()), current_statement_begin__, prog_reader__());
            }
            current_statement_begin__ = 31;
            if (stan::math::is_uninitialized(p0)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: p0";
                stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable p0: ") + msg__.str()), current_statement_begin__, prog_reader__());
            }
            // model body
            current_statement_begin__ = 43;
            lp_accum__.add(binomial_log<propto__>(a, N1, p1));
            current_statement_begin__ = 44;
            lp_accum__.add(binomial_log<propto__>(c, N0, p0));
            current_statement_begin__ = 45;
            lp_accum__.add(normal_log<propto__>(X0, mX0, pow((1 / precX0), 0.5)));
            current_statement_begin__ = 46;
            lp_accum__.add(normal_log<propto__>(X1, mcx1, pow((1 / preccx1), 0.5)));
            current_statement_begin__ = 47;
            lp_accum__.add(normal_log<propto__>(logit_pi0, mLogit_pi0, sLogit_pi0));
            current_statement_begin__ = 48;
            lp_accum__.add(normal_log<propto__>(LOR_c, mLOR_c, sLOR_c));
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("logit_pi0");
        names__.push_back("LOR_c");
        names__.push_back("X0");
        names__.push_back("X1");
        names__.push_back("pi1");
        names__.push_back("pi0");
        names__.push_back("ORadj");
        names__.push_back("Se");
        names__.push_back("Sp");
        names__.push_back("mcx1");
        names__.push_back("preccx1");
        names__.push_back("p1");
        names__.push_back("p0");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_fixedCorr_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        double logit_pi0 = in__.scalar_constrain();
        vars__.push_back(logit_pi0);
        double LOR_c = in__.scalar_constrain();
        vars__.push_back(LOR_c);
        double X0 = in__.scalar_constrain();
        vars__.push_back(X0);
        double X1 = in__.scalar_constrain();
        vars__.push_back(X1);
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            // declare and define transformed parameters
            current_statement_begin__ = 23;
            double pi1;
            (void) pi1;  // dummy to suppress unused var warning
            stan::math::initialize(pi1, DUMMY_VAR__);
            stan::math::fill(pi1, DUMMY_VAR__);
            current_statement_begin__ = 24;
            double pi0;
            (void) pi0;  // dummy to suppress unused var warning
            stan::math::initialize(pi0, DUMMY_VAR__);
            stan::math::fill(pi0, DUMMY_VAR__);
            current_statement_begin__ = 25;
            double ORadj;
            (void) ORadj;  // dummy to suppress unused var warning
            stan::math::initialize(ORadj, DUMMY_VAR__);
            stan::math::fill(ORadj, DUMMY_VAR__);
            current_statement_begin__ = 26;
            double Se;
            (void) Se;  // dummy to suppress unused var warning
            stan::math::initialize(Se, DUMMY_VAR__);
            stan::math::fill(Se, DUMMY_VAR__);
            current_statement_begin__ = 27;
            double Sp;
            (void) Sp;  // dummy to suppress unused var warning
            stan::math::initialize(Sp, DUMMY_VAR__);
            stan::math::fill(Sp, DUMMY_VAR__);
            current_statement_begin__ = 28;
            double mcx1;
            (void) mcx1;  // dummy to suppress unused var warning
            stan::math::initialize(mcx1, DUMMY_VAR__);
            stan::math::fill(mcx1, DUMMY_VAR__);
            current_statement_begin__ = 29;
            double preccx1;
            (void) preccx1;  // dummy to suppress unused var warning
            stan::math::initialize(preccx1, DUMMY_VAR__);
            stan::math::fill(preccx1, DUMMY_VAR__);
            current_statement_begin__ = 30;
            double p1;
            (void) p1;  // dummy to suppress unused var warning
            stan::math::initialize(p1, DUMMY_VAR__);
            stan::math::fill(p1, DUMMY_VAR__);
            current_statement_begin__ = 31;
            double p0;
            (void) p0;  // dummy to suppress unused var warning
            stan::math::initialize(p0, DUMMY_VAR__);
            stan::math::fill(p0, DUMMY_VAR__);
            // do transformed parameters statements
            current_statement_begin__ = 32;
            stan::math::assign(mcx1, (mX1 + ((rhoSe * (X0 - mX0)) * pow((precX1 / precX0), 0.5))));
            current_statement_begin__ = 33;
            stan::math::assign(preccx1, (precX1 / (1 - pow(rhoSe, 2))));
            current_statement_begin__ = 34;
            stan::math::assign(pi0, (stan::math::exp(logit_pi0) / (stan::math::exp(logit_pi0) + 1)));
            current_statement_begin__ = 35;
            stan::math::assign(pi1, (stan::math::exp((logit_pi0 + LOR_c)) / (stan::math::exp((logit_pi0 + LOR_c)) + 1)));
            current_statement_begin__ = 36;
            stan::math::assign(Se, ((1 + (stan::math::exp(X0) / (1 + stan::math::exp(X0)))) / 2));
            current_statement_begin__ = 37;
            stan::math::assign(Sp, ((1 + (stan::math::exp(X1) / (1 + stan::math::exp(X1)))) / 2));
            current_statement_begin__ = 38;
            stan::math::assign(p1, ((pi1 * Se) + ((1 - pi1) * (1 - Sp))));
            current_statement_begin__ = 39;
            stan::math::assign(p0, ((pi0 * Se) + ((1 - pi0) * (1 - Sp))));
            current_statement_begin__ = 40;
            stan::math::assign(ORadj, stan::math::exp(LOR_c));
            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 23;
            check_greater_or_equal(function__, "pi1", pi1, 0);
            check_less_or_equal(function__, "pi1", pi1, 1);
            current_statement_begin__ = 24;
            check_greater_or_equal(function__, "pi0", pi0, 0);
            check_less_or_equal(function__, "pi0", pi0, 1);
            current_statement_begin__ = 26;
            check_greater_or_equal(function__, "Se", Se, 0);
            check_less_or_equal(function__, "Se", Se, 1);
            current_statement_begin__ = 27;
            check_greater_or_equal(function__, "Sp", Sp, 0);
            check_less_or_equal(function__, "Sp", Sp, 1);
            // write transformed parameters
            if (include_tparams__) {
                vars__.push_back(pi1);
                vars__.push_back(pi0);
                vars__.push_back(ORadj);
                vars__.push_back(Se);
                vars__.push_back(Sp);
                vars__.push_back(mcx1);
                vars__.push_back(preccx1);
                vars__.push_back(p1);
                vars__.push_back(p0);
            }
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    std::string model_name() const {
        return "model_fixedCorr";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "logit_pi0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "LOR_c";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "X0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "X1";
        param_names__.push_back(param_name_stream__.str());
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "pi1";
            param_names__.push_back(param_name_stream__.str());
            param_name_stream__.str(std::string());
            param_name_stream__ << "pi0";
            param_names__.push_back(param_name_stream__.str());
            param_name_stream__.str(std::string());
            param_name_stream__ << "ORadj";
            param_names__.push_back(param_name_stream__.str());
            param_name_stream__.str(std::string());
            param_name_stream__ << "Se";
            param_names__.push_back(param_name_stream__.str());
            param_name_stream__.str(std::string());
            param_name_stream__ << "Sp";
            param_names__.push_back(param_name_stream__.str());
            param_name_stream__.str(std::string());
            param_name_stream__ << "mcx1";
            param_names__.push_back(param_name_stream__.str());
            param_name_stream__.str(std::string());
            param_name_stream__ << "preccx1";
            param_names__.push_back(param_name_stream__.str());
            param_name_stream__.str(std::string());
            param_name_stream__ << "p1";
            param_names__.push_back(param_name_stream__.str());
            param_name_stream__.str(std::string());
            param_name_stream__ << "p0";
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__) return;
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "logit_pi0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "LOR_c";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "X0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "X1";
        param_names__.push_back(param_name_stream__.str());
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "pi1";
            param_names__.push_back(param_name_stream__.str());
            param_name_stream__.str(std::string());
            param_name_stream__ << "pi0";
            param_names__.push_back(param_name_stream__.str());
            param_name_stream__.str(std::string());
            param_name_stream__ << "ORadj";
            param_names__.push_back(param_name_stream__.str());
            param_name_stream__.str(std::string());
            param_name_stream__ << "Se";
            param_names__.push_back(param_name_stream__.str());
            param_name_stream__.str(std::string());
            param_name_stream__ << "Sp";
            param_names__.push_back(param_name_stream__.str());
            param_name_stream__.str(std::string());
            param_name_stream__ << "mcx1";
            param_names__.push_back(param_name_stream__.str());
            param_name_stream__.str(std::string());
            param_name_stream__ << "preccx1";
            param_names__.push_back(param_name_stream__.str());
            param_name_stream__.str(std::string());
            param_name_stream__ << "p1";
            param_names__.push_back(param_name_stream__.str());
            param_name_stream__.str(std::string());
            param_name_stream__ << "p0";
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__) return;
    }
}; // model
}  // namespace
typedef model_fixedCorr_namespace::model_fixedCorr stan_model;
#ifndef USING_R
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}
#endif
#endif