#ifndef SOLVERFACTORY_H
#define SOLVERFACTORY_H

#include "MF_Solver1D_Yee.h"
#include "MF_Solver2D_Yee.h"
#include "MF_Solver2D_Cowan.h"

#include "Params.h"

#include "Tools.h"

class SolverFactory {
public:
    static Solver* create(Params& params) {
        Solver* solver = NULL;
        if ( params.geometry == "1d3v" ) {
            solver = new MF_Solver1D_Yee(params);
        }
        else if ( params.geometry == "2d3v" ) {
	    if (params.maxwell_sol == "Cowan")
            solver = new MF_Solver2D_Cowan(params);
	    else 
	    solver = new MF_Solver2D_Yee(params);
        }
        else {
            ERROR( "Unknwon geometry : " << params.geometry );
        }
        return solver;
    }

};

#endif