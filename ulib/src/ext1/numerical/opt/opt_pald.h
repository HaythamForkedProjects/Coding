/* The MIT License

   Copyright (C) 2015 Zilong Tan (eric.zltan@gmail.com)

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the
   "Software"), to deal in the Software without restriction, including
   without limitation the rights to use, copy, modify, merge, publish,
   distribute, sublicense, and/or sell copies of the Software, and to
   permit persons to whom the Software is furnished to do so, subject to
   the following conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
*/

#ifndef _ULIB_OPT_PALD_H
#define _ULIB_OPT_PALD_H

#include <stdint.h>
#include <gsl/gsl_matrix.h>

namespace ulib {

class pald {
public:
    const double RHOMAX = 10;
    const double ZLIMIT = 1e10;

    struct problem {
	// Project the proposed decision vector @x to the nearest
	// point The @x will be replaced with the new point.
	virtual void proj(gsl_vector *x) = 0;
	// Evaluate the value of the objective vector at @x, and store
	// the objective vector in @y.
	virtual void eval(const gsl_vector *x, gsl_vector *y) = 0;
    };

    void
    set_rhomax(double rm)
    { _rhomax = rm; }

    void
    set_zlimit(double zl)
    { _zlimit = zl; }

    // Solve the problem @prob in the minimization direction.
    // Each row of the @mxval corresponds to the @x at each
    // iteration.
    // Each column of @mfval corresponds to the objective vector at
    // each iteration.
    void operator()(problem *prob,
		    gsl_vector *vx0,       // intitial n-dimensional point
		    size_t niter,          // number of iterations
		    size_t bs,             // mini-batch size
		    double beta,           // perturbation width
		    double alpha,          // step size
		    double lambda,         // regularization factor
		    double tau,            // smoothing parameter
		    const gsl_vector *vub, // constant constraints
		    gsl_matrix *mxval,     // niter-by-n matrix
		    gsl_matrix *mfval);    // k-by-niter matrix

    pald();
    ~pald();

private:
    double unif();

    static double
    kernel(const gsl_vector * x, double tau);

    static void
    positive_components(gsl_matrix *mp, const gsl_matrix *m);

    static void
    negative_components(gsl_matrix *mn, const gsl_matrix *m);

    // internal routines
    void
    perturb(problem *prob,
	    const gsl_vector *vx,
	    size_t iter,
	    double beta,
	    gsl_matrix *mdx,
	    gsl_matrix *mny,
	    gsl_vector *vt);

    static void
    ortho_proj(const gsl_matrix *mdx,
	       double lambda,
	       double tau,
	       gsl_matrix *mp);

    static void
    jacob_trans(const gsl_matrix *mp,
		const gsl_matrix *mny,
		const gsl_matrix *my,
		gsl_matrix *mjt);

    static void
    proxy_grad(const gsl_matrix *mp,
	       const gsl_matrix *mny,
	       const gsl_matrix *my,
	       const gsl_matrix *mub,
	       const gsl_vector *vw,
	       double rho,
	       gsl_vector *vds);

    void
    comp_weight(const gsl_matrix *mjt,
		const gsl_vector *vni,
		gsl_vector *vw);

    double
    comp_rho(const gsl_matrix *mjt,
	     const gsl_vector *vni,
	     const gsl_vector *vw);


    double _rhomax;
    double _zlimit;

// RNG context
    uint64_t _u, _v, _w;
};

} // namespace ulib

#endif
