#define MASS 1.//(1./MSUNCM) //so that x-coordinate in centimeters

// which problem
#define FASTWAVE 1    // works poorly in hybrid 
#define ALFVEN 2      // works less well in hybrid
#define ALFVEN2 3     // seems to work well in hybrid
#define THREEWAVE 4   
#define BREAKDOWN 5  

#define FFPROBLEM 4

/************************************/
//restart
/************************************/
//#define RESTART 
#define RESTARTNUM -1
#define RESTARTGENERALINDICES

#define DOFIXUPS 1
#define DOU2PRADFIXUPS 0
#define DOU2PMHDFIXUPS 1
#define DORADIMPFIXUPS 1

/************************************/
//magnetic fields
/************************************/
#define MAGNFIELD

#define VELPRIM VELR
//#define ENFORCEENTROPY
//#define NOLOGINS

#define FORCEFREE
//#define FORCEFREE_PARALLEL_COLD
//#define FORCEFREE_PARALLEL_ENTROPY

//#define HYBRID_FORCEFREE
#ifdef HYBRID_FORCEFREE
//#define HYBRID_FORCEFREE_SIGMACUT 50
#define HYBRID_FORCEFREE_WIDTH .25//0.25
#define HYBRID_FORCEFREE_XCUT 0.5
#endif //HYBRID_FORCEFREE

/************************************/
//coordinates / resolution
/************************************/
#define MYCOORDS MINKCOORDS
#if (FFPROBLEM==4)
#define LLL 0.5
#elif (FFPROBLEM==5)
#define LLL 0.25
#else
#define LLL 1.
#endif

#define MINX -2*LLL
#define MAXX 2*LLL
#define MINY -2*LLL
#define MAXY 2*LLL
#define MINZ 0.
#define MAXZ 1.
#define TNX 256//512
#define TNY 1//256
#define TNZ 1
#define NTX 1
#define NTY 1
#define NTZ 1

#define COPY_XBC
#define PERIODIC_YBC
#define PERIODIC_ZBC

/************************************/
//Output
/************************************/
#define OUTCOORDS MYCOORDS
#define SIMOUTPUT 2
#define OUTPUTINGU
#define DTOUT1 0.01 //res
#define DTOUT2 1.e20 //avg

/************************************/
//reconstruction / stepping
/************************************/
#define INT_ORDER 1
#define TIMESTEPPING RK2HEUN
#define TSTEPLIM .5
#define FLUXLIMITER 1
#define MINMOD_THETA  1.5
#define NOUTSTOP 150
//#define NSTEPSTOP 1
//#define ALLSTEPSOUTPUT 1

/************************************/
//rhd floors
/************************************/
#define UURHORATIOMIN 1.e-15
#define B2RHORATIOMAX 1000.
#define UURHORATIOMAX 1000.
#define B2UURATIOMAX 10000.

#define GAMMAMAXHD 100.
#define B2RHOFLOORFRAME FFFRAME 

#define GAMMAMAXFF 100.

/************************************/
//physics
/************************************/
//#define GAMMA (5./3.)
#define GAMMA (4./3.)
#define HFRAC 1.
#define HEFRAC 0.

/************************************/
//problem parameters
/************************************/

#define RHOINIT 1.
#define PINIT 1.
#define UUINIT PINIT/(GAMMA-1.)

#define SIGMAINIT 100
#define THETAINIT .25

// vary initial sigma from left to right
//#define SIGMARAMP
#ifdef SIGMARAMP

//#define INIT_SIGMA_TANH
#define INIT_SIGMA_LIN

//#define INIT_SIGMA_HIGHLEFT
#define SIGMAINITMIN 10
#define SIGMAINITWIDTH 5
#define SIGMAINITOFFSET -.5
//#define UUINIT RHOINIT*THETAINIT/(GAMMA-1.)/MU_GAS//endenCGS2GU(1.*CCC*CCC*1.e-3)
#endif //SIGMARAMP
