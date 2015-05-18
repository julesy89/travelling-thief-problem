#ifndef _GENETIC_H
#define _GENETIC_H

/*
 * This header specifies the interface for the genetic algorithm part of LKH.
 */

typedef void (*CrossoverFunction) ();

int MaxPopulationSize; /* The maximum size of the population */ 
int PopulationSize;    /* The current size of the population */

CrossoverFunction Crossover;

int **Population;      /* Array of individuals (solution tours) */
GainType *Fitness;     /* The fitness (tour cost) of each individual */



#endif
