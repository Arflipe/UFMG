fun myappend([], L) = L
  | myappend(H::T, L) = H::myappend(T, L);

myappend([1,2,3], [4,5,6])