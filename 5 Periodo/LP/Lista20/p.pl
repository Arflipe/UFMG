parent(kim,holly).
parent(margaret,kim).
parent(margaret,kent).
parent(esther,margaret).
parent(herbert,margaret).
parent(herbert,jean).
% parent(jean, victor).

greatgrandparent(GGP,GGC) :- parent(GGP,GP), parent(GP,P), parent(P,GGC).

% 1- Define a predicate mother

woman(kim).
woman(holly).
woman(margaret).
woman(esther).
woman(jean).

mother(X, Y) :- woman(X), parent(X, Y).

% 2- Define father

man(kent).
man(herbert).
% man(victor).

father(X, Y) :- man(X), parent(X, Y).

% 3- Define sister

sister(X, Y) :- woman(X), parent(Z, X), parent(Z, Y), X \= Y.

% 4- Define grandson

grandson(X, Y) :- man(X), parent(Z, X), parent(Y, Z).

% 5- Define firstCousin

firstCousin(X, Y) :- parent(XP, X), parent(YP, Y), parent(GP, XP), parent(GP, YP), X \= Y, XP \= YP.

% 6- Define descendant

descendant(X, Y) :- parent(Y, X).
descendant(X, Y) :- parent(Z, X), descendant(Z, Y).

% 7- Define third(X, Y) that is true if Y is the third element of list X

third([_, _, Y | _], Y).

% 8- Define firstPair(X) that is true if X is a list with at least 2 elements, the first being the same as the second

firstPair([X, X | _]).

% 9- Define del3(X, Y) that is true if Y is a list equal to X, but with the third element removed.

del3([X, Y | T], [X, Y, _ | T]).

% 10- Define duplist(X, Y) that is true if Y is a list equal to X, but with every element repeated

duplist([], []).
duplist([X | TX], [X, X | TY]) :- duplist(TX, TY).

% 11- Define isDuped(Y) that is true if Y is the same list Y from the previous exercise

isDuped(Y) :- duplist(_, Y).

% 12- Define oddSize(X)

oddSize([_]).
oddSize([_, _ | T]) :- oddSize(T).

% 13- Define evenSize

evenSize(X) :- \+ oddSize(X).

% 14- Define prefix(X, Y)

prefix([], _).
prefix([X | TX], [X | TY]) :- prefix(TX, TY).