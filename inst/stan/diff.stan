data {
  int<lower=0> a;
  int<lower=0> N1;
  int<lower=0> c;
  int<lower=0> N0;
  vector[4] Mu;
  matrix[4,4] varZ;
  real mLogit_pi0;
  real<lower=0> sLogit_pi0;
  real mLOR_c;
  real<lower=0> sLOR_c;
}
parameters {
  // Parameter values that are too large will cause exponential to go to inf, causing nan
  real<lower=-200, upper=200> logit_pi0;
  real<lower=-200, upper=200> LOR_c;
  vector<lower=-200, upper=200>[4] Z;
}
transformed parameters {
  real<lower=0, upper=1> pi1;
  real<lower=0, upper=1> pi0;
  real<lower=0> ORadj;
  real<lower=0, upper=1> Se0;
  real<lower=0, upper=1> Se1;
  real<lower=0, upper=1> Sp0;
  real<lower=0, upper=1> Sp1;
  real<lower=0, upper=1> p1;
  real<lower=0, upper=1> p0;
  Se0 = (1 + exp(Z[1]) / (1 + exp(Z[1]))) / 2;
  Se1 = (1 + exp(Z[2]) / (1 + exp(Z[2]))) / 2;
  Sp0 = (1 + exp(Z[3]) / (1 + exp(Z[3]))) / 2;
  Sp1 = (1 + exp(Z[4]) / (1 + exp(Z[4]))) / 2;
  pi0 = exp(logit_pi0) / (exp(logit_pi0) + 1);
  pi1 = exp(logit_pi0 + LOR_c) / (exp(logit_pi0 + LOR_c) + 1);
  p1 = pi1 * Se1 + (1 - pi1) * (1 - Sp1);
  p0 = pi0 * Se0 + (1 - pi0) * (1 - Sp0);
  ORadj = exp(LOR_c);
}
model {
  logit_pi0 ~ normal(mLogit_pi0, sLogit_pi0);
  LOR_c ~ normal(mLOR_c, sLOR_c);
  a ~ binomial(N1, p1);
  c ~ binomial(N0, p0);
  Z ~ multi_normal(Mu, varZ);
}
