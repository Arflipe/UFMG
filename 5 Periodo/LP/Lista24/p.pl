% This is the interpreter to the language Three with dynamic scope

val3(plus(X, Y), Context, Value) :-
  val3(X, Context, XValue),
  val3(Y, Context, YValue),
  Value is XValue + YValue.

val3(times(X, Y), Context, Value) :-
  val3(X, Context, XValue),
  val3(Y, Context, YValue),
  Value is XValue * YValue.

val3(const(X), _, X).

val3(var(X), Context, Value) :-
  lookup(X, Context, Value).

val3(let(X, Exp1, Exp2), Context, Value2) :-
  val3(Exp1, Context, Value1),
  val3(Exp2, [bind(X, Value1) | Context], Value2).

val3(fn(Formal, Body), _, fval(Formal, Body)).

val3(apply(Function, Actual), Context, Value) :-
  val3(Function, Context, fval(Formal, Body)),
  val3(Actual, Context, ParamValue),
  val3(Body, [bind(Formal, ParamValue)|Context], Value).

lookup(Variable, [bind(Variable, Value)|_], Value).
lookup(VarX, [bind(VarY, _)|Rest], Value) :-
  VarX \= VarY, lookup(VarX, Rest, Value).

/*
   val3(let(y, const(1), let(y, const(2), var(y))), nil, X).
 
   val3(let(a, plus(const(3), const(4)), times(var(a), const(5))), nil, V).

   val3(apply(fn(x,times(var(x), var(x))), const(3)), nil, X).

   val3(let(x, const(1), let(f, fn(n, plus(var(n), var(x))), let(x, const(2), apply(var(f), const(0))))), nil, X).
 */

% 1- Consider the expressions: let val x = e1 in e2 and (fn x => e2) e1. These are equivalent.
% 1-a) Show that the conditions to evaluate <apply(fn(x, e2), e1), C> -> v are equivalent to the conditions to evaluate <let(x, e1, e2), C> -> v.
/*
		<apply(fn(x, e2), e1), C> -> v													<let(x, e1, e2), C>

				apply()										C = []								let()			C = []

		fn()				e1								C = []						x		e1		e2		C = []
		fval(x, e2)			e2, [(x, val(e2))|C], value									x	val(e1)


*/

% This is the interpreter to the language Three with static scope

val4(plus(X, Y), Context, Value) :-
  val4(X, Context, XValue),
  val4(Y, Context, YValue),
  Value is XValue + YValue.

val4(times(X, Y), Context, Value) :-
  val4(X, Context, XValue),
  val4(Y, Context, YValue),
  Value is XValue * YValue.

val4(const(X), _, X).

val4(var(X), Context, Value) :-
  lookup(X, Context, Value).

val4(let(X, Exp1, Exp2), Context, Value2) :-
  val4(Exp1, Context, Value1),
  val4(Exp2, [bind(X, Value1) | Context], Value2).

val4(fn(Formal, Body), Context, fval(Formal, Body, Context)).

val4(apply(Function, Actual), Context, Value) :-
  val4(Function, Context, fval(Formal, Body, Nesting)),
  val4(Actual, Context, ParamValue),
  val4(Body, [bind(Formal, ParamValue)|Nesting], Value).

lookup(Variable, [bind(Variable, Value)|_], Value).
lookup(VarX, [bind(VarY, _)|Rest], Value) :-
  VarX \= VarY, lookup(VarX, Rest, Value).

/*
   val4(let(y, const(1), let(y, const(2), var(y))), nil, X).
 
   val4(let(a, plus(const(3), const(4)), times(var(a), const(5))), nil, V).

   val4(apply(fn(x,times(var(x), var(x))), const(3)), nil, X).

   val4(let(x, const(1), let(f, fn(n, plus(var(n), var(x))), let(x, const(2), apply(var(f), const(0))))), nil, X).

   val4(let(f,fn(x,let(g,fn(y,plus(var(y),var(x))), var(g))), apply(apply(var(f),const(1)),const(2))),nil, X).
 */

% 1-b) Show the same thing, but this time using the static scope interpreter

% 2- The goal of this exercise is to define the language Four. An example of a program in Four:

let
	val fact = fn x => if x < 2 then x else x * x fact(x-1)
in
	fact 5
end

% As you can see, the language Four extends the language Three with 3 new constructs: <, - and if-then-else.

% 2-a) Extend Three to incorporate the new constructs. Make sure it is not ambiguous

% 2-b) Define three new node types fot the AST that incorporates the new syntax. Use dynamic scope for recursion

% 2-c) Give a natural semantics to the language Four

% 3-a) Extend the language Four to allow simple definition of functions, like:

let fun f x = x + 1 in f 1 end

% 3-b) Define the new node types for the AST

% 3-c) Give a natural semantics to the extended language

% 4- Write predicate gcd(N1, N2, Q) that is true if Q is the greatest common divisor of N1 and N2.
