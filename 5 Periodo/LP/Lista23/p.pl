% 1- Write predicate max(X, Y, Z) that gets X and Y and unifies the biggest with Z

max(X, Y, X) :- X >= Y.
max(X, Y, Y) :- X < Y.

% 2- Write predicate maxList(L, M) that gets a list L and unifies the biggest element with M

maxList([X], X).
maxList([H|T], M) :- maxList(T, M2), max(H, M2, M). 

% 3- Write predicate ordered(L) that is true if L is in ascending order

ordered([]).
ordered([_]).
ordered([H1,H2|T]) :- H1 =< H2, ordered([H2|T]).

% 4- Write mergeSort(In, Out) that is true if Out is sorted version of In

mSort([], []).
mSort([X], [X]).
mSort(In, Out) :- split(In, L1, L2), mSort(L1, LL1), mSort(L2, LL2), merge2(LL1, LL2, Out).

split([], [], []).
split([H], [H], []).
split([H1, H2|T], [H1|L1], [H2|L2]) :- split(T, L1, L2).

merge2([], [], []).
merge2(L1, [], L1).
merge2([], L2, L2).
merge2([H1|T1], [H2|T2], [H1|T]) :- H1 =< H2, merge2(T1, [H2|T2], T).
merge2([H1|T1], [H2|T2], [H2|T]) :- H2 < H1, merge2([H1|T1], T2, T).

% 5- Write predicate nqueens(N, X).

nocheck(_, []).
nocheck(X1/Y1, [X2/Y2|R]) :- 
	X1 =\= X2,
	Y1 =\= Y2,
	abs(X2 - X1) =\= abs(Y2 - Y1),
	nocheck(X1/Y1, R).

range(I, I, [I]).
range(I, K, [I|T]) :- I =< K, II is I + 1, range(II, K, T).

% legal([]).
% legal([X/Y | Rest]) :-
%   legal(Rest),
%   member(X,[1,2,3,4,5,6,7,8]),
%   member(Y,[1,2,3,4,5,6,7,8]),
%   nocheck(X/Y, Rest).
legal(_, []).
legal(Range, [X/Y|R]) :-
	legal(Range, R),
	member(X, Range),
	member(Y, Range),
	nocheck(X/Y, R).

nqueens(0, []).
nqueens(N, X) :- 
	length(X, N),
	range(1, N, Range),
	legal(Range, X).
	
% nqueens(0, []).
% nqueens(N, [X/Y|R]) :- 
% 	nqueens(N, R),
% 	range(1, N, L),
% 	member(X, L),
% 	member(Y, L),
% 	nocheck(X/Y, R).
