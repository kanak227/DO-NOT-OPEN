In singleton design pattern an object is created only once for a class , and is accessed using the same object multiple times

2 ways to do it :-

1. Lazy_way (Samosa.java)
Issues:-
: During threading , threads are synchronous so objects might be created more than once.
-- can be solved by using synchronized keyword at the time of object creation.

2. Eager_way (Jalebi.java)
Issues :-
: Objects created when not needed to be -- not a good way makes software slow
