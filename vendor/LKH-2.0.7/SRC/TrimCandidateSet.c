#include "LKH.h"

/*
 * The TrimCandidateSet function takes care that each node has 
 * associated at most MaxCandidates candidate edges.                         
 */

void TrimCandidateSet(int MaxCandidates)
{
    Node *From;
    Candidate *NFrom;
    int Count;

    From = lkh.FirstNode;
    do {
        Count = 0;
        for (NFrom = From->CandidateSet; NFrom->To; NFrom++)
            Count++;
        if (Count > MaxCandidates) {
            assert(From->CandidateSet =
                   (Candidate *) realloc(From->CandidateSet,
                                         (MaxCandidates +
                                          1) * sizeof(Candidate)));
            From->CandidateSet[MaxCandidates].To = 0;
        }
    } while ((From = From->Suc) != lkh.FirstNode);
}
