//
// Created by robgrzel on 14.06.17.
//

#ifndef UTILS_PHYS_H
#define UTILS_PHYS_H

#define elif else if

#define  PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286L

#define PI_2         PI/2LL
#define PI_3         PI/3LL
#define PI_4         PI/4LL
#define PI_5         PI/5LL
#define PI_6     PI/6LL
#define PI_12    PI/12LL
#define DEG PI/180LL
#define RAD 180LL/PI

#define deg2rad( x )    ((x) * DEG)
#define rad2deg( x )    ((x) * RAD)


#define  GRAV 9.81


//#44.1 Fundamental Constants
#define SPEED_OF_LIGHT    2.997924580000e+08
#define VACUUM_PERMEABILITY    1.256637061440e-06
#define VACUUM_PERMITTIVITY    8.854187817000e-12
#define PLANCKS_CONSTANT_H    6.626068960000e-34
#define PLANCKS_CONSTANT_HBAR    1.054571628250e-34
#define AVOGADRO    6.022141990000e+23
#define FARADAY    9.648534297750e+04
#define BOLTZMANN    1.380650400000e-23
#define MOLAR_GAS    8.314472000000e+00
#define STANDARD_GAS_VOLUME    2.271098100000e-02
#define STEFAN_BOLTZMANN_CONSTANT    5.670400473740e-08
#define GAUSS    1.000000000000e-04
//#44.2 Astronomy and Astrophysics
#define ASTRONOMICAL_UNIT    1.495978706910e+11
#define GRAVITATIONAL_CONSTANT    6.673000000000e-11
#define LIGHT_YEAR    9.460536207070e+15
#define PARSEC    3.085677581350e+16
#define GRAV_ACCEL    9.806650000000e+00
#define SOLAR_MASS    1.988920000000e+30
//#44.3 Atomic and Nuclear Physics
#define ELECTRON_CHARGE    1.602176487000e-19
#define ELECTRON_VOLT    1.602176487000e-19
#define UNIFIED_ATOMIC_MASS    1.660538782000e-27
#define MASS_ELECTRON    9.109381880000e-31
#define MASS_MUON    1.883531090000e-28
#define MASS_PROTON    1.672621580000e-27
#define MASS_NEUTRON    1.674927160000e-27
#define FINE_STRUCTURE    7.297352533000e-03
#define RYDBERG    2.179871969680e-18
#define BOHR_RADIUS    5.291772083000e-11
#define ANGSTROM    1.000000000000e-10
#define BARN    1.000000000000e-28
#define BOHR_MAGNETON    9.274008990000e-24
#define NUCLEAR_MAGNETON    5.050783170000e-27
#define ELECTRON_MAGNETIC_MOMENT    9.284763620000e-24
#define PROTON_MAGNETIC_MOMENT    1.410606633000e-26
#define THOMSON_CROSS_SECTION    6.652458936990e-29
#define DEBYE    3.335640951980e-30
//#44.4 Measurement of Time
#define MINUTE    6.000000000000e+01
#define HOUR    3.600000000000e+03
#define DAY    8.640000000000e+04
#define WEEK    6.048000000000e+05
//#44.5 Imperial Units
#define INCH    2.540000000000e-02
#define FOOT    3.048000000000e-01
#define YARD    9.144000000000e-01
#define MILE    1.609344000000e+03
#define MIL    2.540000000000e-05
//#44.6 Speed and Nautical Units
#define KILOMETERS_PER_HOUR    2.777777777780e-01
#define MILES_PER_HOUR    4.470400000000e-01
#define NAUTICAL_MILE    1.852000000000e+03
#define FATHOM    1.828800000000e+00
#define KNOT    5.144444444440e-01
//#44.7 Printers Units
#define POINT    3.527777777780e-04
#define TEXPOINT    3.514598035150e-04

//#44.8 Volume, Area and Length
#define MICRON    1.000000000000e-06
#define HECTARE    1.000000000000e+04
#define ACRE    4.046856422410e+03
#define LITER    1.000000000000e-03
#define US_GALLON    3.785411784020e-03
#define CANADIAN_GALLON    4.546090000000e-03
#define UK_GALLON    4.546092000000e-03
#define QUART    9.463529460040e-04
#define PINT    4.731764730020e-04
//#44.9 Mass and Weight
#define POUND_MASS    4.535923700000e-01
#define OUNCE_MASS    2.834952312500e-02
#define TON    9.071847400000e+02
#define METRIC_TON    1.000000000000e+03
#define UK_TON    1.016046908800e+03
#define TROY_OUNCE    3.110347500000e-02
#define CARAT    2.000000000000e-04
#define GRAM_FORCE    9.806650000000e-03
#define POUND_FORCE    4.448221615260e+00
#define KILOPOUND_FORCE    4.448221615260e+03
#define POUNDAL    1.382550000000e-01
//#44.11 Pressure
#define BAR    1.000000000000e+05
#define STD_ATMOSPHERE    1.013250000000e+05
#define TORR    1.333223684210e+02
#define METER_OF_MERCURY    1.333223684210e+05
#define INCH_OF_MERCURY    3.386388157890e+03
#define INCH_OF_WATER    2.490889000000e+02
#define PSI    6.894757293170e+03
//#44.12 Viscosity
#define POISE    1.000000000000e-01
#define STOKES    1.000000000000e-04
//#44.13 Light and Illumination
#define STILB    1.000000000000e+04
#define LUMEN    1.000000000000e+00
#define LUX    1.000000000000e+00
#define PHOT    1.000000000000e+04
#define FOOTCANDLE    1.076000000000e+01
#define LAMBERT    1.000000000000e+04
#define FOOTLAMBERT    1.076391040000e+01
//#44.15 Force and Energy
#define NEWTON    1.000000000000e+00
#define DYNE    1.000000000000e-05
#define JOULE    1.000000000000e+00
#define ERG    1.000000000000e-07
//#44.16 Prefixes
#define N_YOTTA    1.000000000000e+24
#define N_ZETTA    1.000000000000e+21
#define N_EXA    1.000000000000e+18
#define N_PETA    1.000000000000e+15
#define N_TERA    1.000000000000e+12
#define N_GIGA    1.000000000000e+09
#define N_MEGA    1.000000000000e+06
#define N_KILO    1.000000000000e+03
#define N_MILLI    1.000000000000e-03
#define N_MICRO    1.000000000000e-06
#define N_NANO    1.000000000000e-09
#define N_PICO    1.000000000000e-12
#define N_FEMTO    1.000000000000e-15
#define N_ATTO    1.000000000000e-18
#define N_ZEPTO    1.000000000000e-21
#define N_YOCTO    1.000000000000e-24




#endif //UTILS_PHYS_H