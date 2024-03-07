% 1- Transform into tail recursive funtions
% 1-a) sum(L, V) - V is the sum of the elements of L
sum([], 0).
sum([H|T], X) :- sum(T, XAux), X is XAux + H.

sum_acc([], Acc, Acc).
sum_acc([H|T], Acc, X) :- Acc2 is Acc + H, sum_acc(T, Acc2, X).

sum2(L, V) :- sum_acc(L, 0, V).

% 1-b) myreverse(L, R) - R is the reverse of L
myappend([], L, L).
myappend([H|T], L, [H|LAux]) :- myappend(T, L, LAux).

myreverse([], []).
myreverse([H|T], R) :- myreverse(T, RT), myappend(RT, [H], R).

myreverse_acc([], Acc, Acc).
myreverse_acc([H|T], Acc, X) :- myreverse_acc(T, [H|Acc], X).
% myreverse_acc([H|T], Acc, X) :- Acc2 is myappend(H, Acc, Acc2), myreverse_acc(T, Acc2, X).

% 1-c) What is the advantage of tail recursive functions?

	% Tail recursion makes it so that there is only one actual recursive call, so there is only one activation record in the stack at a time.

% 2- Implement SubsetSum(U, N, S) in prolog

subset([], []).
subset([H|T], [H|R]) :- subset(T, R).
subset([_|T], R) :- subset(T, R).

sumList([], Acc, Acc).
sumList([H|T], Acc, X) :- Acc2 is Acc + H, sumList(T, Acc2, X).

subsetSum(U, N, S) :- subset(U, S), sumList(S, 0, N).

% 3- Find out what the predicate riddle does and implement it more efficiently

riddle(X,_) :- length(X, XL), XL = 0.
riddle(_,Y) :- length(Y,YL), YL = 0.

	% It checks if any of the lists is empty

riddle2([], _) :- true.
riddle2(_, []) :- true.

% 4- Find out what the predicate enigma does and implement it more efficiently

enigma(List1, N, List2) :- length(Dummy, N), append(List2, Dummy, List1).

	% It removes the last N elements of List1 and puts them in List2

% enigma2([], _, []).
% enigma2(_, 0, []).
% enigma2([H|T], N, [H|L]) :- N2 is N - 1, enigma2(T, N2, L).

% removeN([], _, [])
removeN(_, 0, []).
removeN([H|T], N, [H|X]) :- N2 is N - 1, removeN(T, N2, X).

enigma2(L, N, X) :- length(L, Y), NN is Y - N, removeN(L, NN, X).

% 5- Rewrite the predicate below so that it uses tail recursion.

xfactorial(1, 1).
xfactorial(N, FN) :- NextN is N-1, xfactorial(NextN, FNextN), FN is FNextN * N.

xfactorial_acc(1, Acc, Acc).
xfactorial_acc(N, Acc, FN) :- N2 is N - 1, Acc2 is N * Acc, xfactorial_acc(N2, Acc2, FN).

% 6-a) In a language like Java, that has collateral effects, how to know if the implementation reutilize parts of data structures

	% You can create the data structure D, then create a new one N = D, change N and see if D is also changed.

% 6-b) What about languages that have no collateral effect, like Prolog and SML, how to see?

	% You have to look at the implementation of the language

% 7-a) Write functions init and zero for this program in C:

	% const int N = 600;

	% void mult1(int Z[N][N], int X[N][N], int Y[N][N]) {
	% 	int i, j, k;
	% 	for (i = 0; i < N; i++)
	% 		for (j = 0; j < N; j++)
	% 			for (k = 0; k < N; k++)
	% 				Z[i][j] += X[i][k] * Y[k][j];
	% }

	% void mult2(int Z[N][N], int X[N][N], int Y[N][N]) {
	% 	int i, j, k;
	% 	for (i = 0; i < N; i++)
	% 		for (j = 0; j < N; j++)
	% 			for (k = 0; k < N; k++)
	% 				Z[i][k] += X[i][j] * Y[j][k];
	% }

	% int main() {
	% 	int X[N][N], Y[N][N], Z[N][N];
	% 	init(X);
	% 	init(Y);
	% 	zero(Z);
	% 	mult1(Z, X, Y);
	% }

% void init(int X[N][N]) {
% 	int i, j;
% 	for (i = 0; i < N; i++)
% 		for (j = 0; j < N; j++)
% 			X[i][j] = rand() % 100;
% }

% void zero(int X[N][N]) {
% 	int i, j;
% 	for (i = 0; i < N; i++)
% 		for (j = 0; j < N; j++)
% 			X[i][j] = 0;
% }

% 7-b) Test mult2 and mult1 using the function time from UNIX. Get the mean time from executing 3 times. Which is more efficient?

	% mult2: 0,867
	% mult1: 1,033

	% mult2 is more efficient.

% 7-c) Why?

	% mult2 has more cache hits than mult1, so it has to go back to RAM fewer times to get the data.