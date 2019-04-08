### R code from vignette source 'BayesSenMC_demo.Rnw'
### Encoding: UTF-8

###################################################
### code chunk number 1: BayesSenMC_demo.Rnw:279-280
###################################################
options(prompt = "R> ", continue = "+  ", width = 70, useFancyQuotes = FALSE, fig.height = 5, fig.width = 7)


###################################################
### code chunk number 2: BayesSenMC_demo.Rnw:283-285 (eval = FALSE)
###################################################
## library("devtools")
## devtools::install_github("formidify/BayesSenMC", build = TRUE, build_opts = c("--no-resave-data", "--no-manual"))


###################################################
### code chunk number 3: BayesSenMC_demo.Rnw:289-292 (eval = FALSE)
###################################################
## library("BayesSenMC")
## vignette("BayesSenMC_demo", package = "BayesSenMC")
## edit(vignette("BayesSenMC_demo", package = "BayesSenMC"))


###################################################
### code chunk number 4: BayesSenMC_demo.Rnw:301-303
###################################################
library("BayesSenMC")
my.mod <- nlmeNDiff(bd_meta, lower = 0)


###################################################
### code chunk number 5: BayesSenMC_demo.Rnw:312-314 (eval = FALSE)
###################################################
## # call library without showing the code
## library("BayesSenMC")


###################################################
### code chunk number 6: BayesSenMC_demo.Rnw:317-328 (eval = FALSE)
###################################################
## # Model with no misclassification
## m.1 <- correctedOR(a = 66, N1 = 11782, c = 243, N0 = 57973, chains = 3, 
## iter = 10000)
## 
## # Model with constant misclassification
## m.2 <- crudeOR(a = 66, N1 = 11782, c = 243, N0 = 57973, se = 0.744, sp = 0.755, 
## chains = 3, iter = 10000)
## 
## # Model with logit bivariate transformed misclassification
## m.3 <- logitOR(a = 66, N1 = 11782, c = 243, N0 = 57973, m.lg.se = 1.069,
## m.lg.sp = 1.126, s.lg.se = 0.893, s.lg.sp = 0.712, chains = 3, iter = 10000)


###################################################
### code chunk number 7: BayesSenMC_demo.Rnw:334-349 (eval = FALSE)
###################################################
## # Model with logit transformed misclassification w/ fixed correlation
## m.4 <- fixedCorrOR(a = 66, N1 = 11782, c = 243, N0 = 57973, m.lg.se = 1.069, 
## m.lg.sp = 1.126, s.lg.se = 0.893, s.lg.sp = 0.712, rho = -0.379, chains = 3, 
## iter = 10000)
## 
## # Model with logit bivariate transformed misclassification 
## # plus Fisher Z transformed correlation
## m.5 <- randCorrOR(a = 66, N1 = 11782, c = 243, N0 = 57973, m.lg.se = 1.069, 
## m.lg.sp = 1.126, s.lg.se = 0.893, s.lg.sp = 0.712, m.z = -0.399, s.z = 0.139, 
## chains = 3, iter = 10000)
## 
## # Model with logit four-variate transformed differential misclassification
## m.6 <- diffOR(a = 66, N1 = 11782, c = 243, N0 = 57973, mu = c(1.069, 1.069, 1.126, 1.126),
## s.lg.se0 = 0.893, s.lg.se1 = 0.893, s.lg.sp0 = 0.712, s.lg.sp1 = 0.712, corr.sesp0 = -0.377, 
## corr.sesp1 = -0.377, corr.group = 0, chains = 3, iter = 10000, traceplot = TRUE)


###################################################
### code chunk number 8: BayesSenMC_demo.Rnw:355-364 (eval = FALSE)
###################################################
## ## extract summary statistics for adjusted odds ratio of the above models
## # each run generates slightly different estimates because of MCMC's inherent stochastic behavior, but the differences are minor for our analysis
## library(rstan)
## s.1 <- rstan::summary(m.1, pars = c("ORadj"))$summary
## s.2 <- rstan::summary(m.2, pars = c("ORadj"))$summary
## s.3 <- rstan::summary(m.3, pars = c("ORadj"))$summary
## s.4 <- rstan::summary(m.4, pars = c("ORadj"))$summary
## s.5 <- rstan::summary(m.5, pars = c("ORadj"))$summary
## s.6 <- rstan::summary(m.6, pars = c("ORadj"))$summary


###################################################
### code chunk number 9: BayesSenMC_demo.Rnw:371-374 (eval = FALSE)
###################################################
## library(ggplot2)
## g1 <- plotOR(m.1, a = 66, N1 = 11782, c = 243, N0 = 57973, se = 0.744,
## sp = 0.755, x.max = 3, y.max = 5, binwidth = 0.1) + ggtitle("(a)")


###################################################
### code chunk number 10: BayesSenMC_demo.Rnw:377-394 (eval = FALSE)
###################################################
## g2 <- plotOR(m.2, a = 66, N1 = 11782, c = 243, N0 = 57973, se = 0.744,
## sp = 0.755, x.max = 3, y.max = 5, binwidth = 0.1) + ggtitle("(b)")
## 
## g3 <- plotOR(m.3, a = 66, N1 = 11782, c = 243, N0 = 57973, se = 0.744,
## sp = 0.755, x.max = 3, y.max = 5, binwidth = 0.1) + ggtitle("(c)")
## 
## g4 <- plotOR(m.4, a = 66, N1 = 11782, c = 243, N0 = 57973, se = 0.744,
## sp = 0.755, x.max = 3, y.max = 5, binwidth = 0.1) + ggtitle("(d)")
## 
## g5 <- plotOR(m.5, a = 66, N1 = 11782, c = 243, N0 = 57973, se = 0.744,
## sp = 0.755, x.max = 3, y.max = 5, binwidth = 0.1) + ggtitle("(e)")
## 
## g6 <- plotOR(m.6, a = 66, N1 = 11782, c = 243, N0 = 57973, se = 0.744,
## sp = 0.755, x.max = 3, y.max = 5, binwidth = 0.1) + ggtitle("(f)")
## 
## # call grid.arrange to format individual distribution plots
## grid.arrange(g1, g2, g3, g4, g5, g6, nrow = 2)


