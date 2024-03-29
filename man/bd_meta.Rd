% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/bd_meta-data.R
\docType{data}
\name{bd_meta}
\alias{bd_meta}
\title{Meta-analysis data on Bipolar Disorder diagnosis accuracy}
\format{
An object of class \code{tbl_df} (inherits from \code{tbl}, \code{data.frame}) with 55 rows and 8 columns.
}
\source{
\url{https://www.sciencedirect.com/science/article/pii/S0165032714006466}
}
\usage{
data(bd_meta)
}
\description{
Records the true positive, true negative, false positive and false negative
of each diagnosis accuracy study. Also includes the type of screening instruments
(Bipolar Spectrum diagnostic scale / HCL-21 / Mood disorder questionnaire), the cut-off
value for diagnostics, and the percentage of bipolar cases that were of bipolar disorder
type II or not specified.
}
\examples{
data(bd_meta)
}
\references{
Carvalho et al. (2015) "Screening for bipolar spectrum disorders: A comprehensive meta-analysis of accuracy studies". Journal of Affective Disorders 172: 337 - 346.
(\href{https://www.sciencedirect.com/science/article/pii/S0165032714006466}{ScienceDirect})
}
\keyword{dataset}
