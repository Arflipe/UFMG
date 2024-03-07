file2list(F, L) :- see(F), read(Y), readData(Y, L), seen.

readData(end_of_file, []) :- !.
readData(X, [X | L]) :- read(Y), readData(Y, L).

findAnagram(F, A, S) :- file2list(F, L), select(S, L, _), name(A, A2), name(S, S2), isAnagram(A2, S2).

isAnagram([], []).
isAnagram([H | T], S) :- select(H, S, S2), isAnagram(T, S2).