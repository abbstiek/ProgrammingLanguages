/*   %Abygail Stiekman%  */
/*      %04/19/2017%     */
/*       %COP4020% 	 */
/*      %Project 4%	 */



menu(X) :- 
   write('\tClass roster management system'), nl,
   write('\t=============================='), nl,
   write('\t            MENU'), nl,
   write('\t=============================='), nl,
   write('\t0. Reset roster'), nl,
   write('\t1. Load roster from file'), nl,
   write('\t2. Store roster to file'), nl,
   write('\t3. Display roster sorted by ID'), nl, 
   write('\t4. Add student to roster'), nl,
   write('\t5. Remove student from roster'), nl,
   write('\t6. Exit'), nl, 
   write('\tEnter your choice (followed by a \'.\'): '),
   read(Sel),
   process(Sel, X).

process(0, X) :-
	nl,
	write('\tReset roster (now empty).'),
	nl, nl, menu([]).

process(1, X) :-
	nl,
	write('\tEnter a filename to load roster from: '),
	read_fileName(F),
	see(F),
	read(Y),
	seen,
	nl, nl, menu(Y).

process(2, X) :-
	nl,
	write('\tEnter a filename to store roster to: '),
	read_fileName(F),
	tell(F),
	writeq(X),
	write(.),
	told,
	nl, nl, menu(X).
	
process(3, X) :-
   nl,
   write('\tDisplay roster, sorted by ID.'),nl,
   naive_sortID(X, Y),
   Num is 1,
   display_record(Y, Num),
   nl, nl, menu(Y).
   
process(4, X) :- 
    nl,
    write('\tAdd a student to the class roster.'),nl,
    read_student_info([A, B, C]),
    nl, nl, menu([[A,B,C] | X]).

process(5, X) :- 
    nl,
    write('\t Enter a student name or ID.'),
	read(I), nl,
	remove(I, X, C), nl,
	menu(C).
	
	
process(6, _) :- write('Good-bye'), nl, !.
process(_, X) :- menu(X).

read_fileName(File) :-
	read(File).

read_student_info([A, B, C]) :-
  write('\tStudent ID: '),
  read(A),
  write('\tStudent Name: '),
  read(B),
  write('\tGrade: '),
  read(C).
  
display_record([], _).
display_record([[A, B, C] | T], Num) :-
	write('\tNo.'),
	write(Num),
	write(': '),
	write('ID = '),
	write(A),
	write(', Name = '),
	format("~s", [B]),
	write(', Grade = '),
	write(C), nl,
	Num2 is Num + 1,
	display_record(T, Num2).

	
%sorting 
perm([],[]).
perm([A|B],X) :- 
	perm(B,C), takeout(A, X, C).

takeout(X, [X|T], T).
takeout(X, [H | L], [H | T]) :- 
	takeout(X, L, T).

naive_sortID(L1, L2):- 
	perm(L1, L2), sortId(L2). 

sortId([]):- 
	write('\n\tNo records to display\n').
sortId([_]).
sortId([[A,B,C], [X,Y,Z] | T]) :- 
	A < X, sortId([[X,Y,Z] | T]).


%remove
remove(_, [],[]) :- 
	write('\n\tStudent does not exist.\n\n').
remove(X, [[X, N, G] | L], L) :- 
	write('\n\tStudent removed.\n').
remove(X, [[I, X, G] | L], L) :- 
	write('\n\tStudent removed.\n').
remove(X, [[I, N, G] | L], [[I, N, G] | T]) :- 
	remove(X, L, T).

%Grade
naive_sortGrade(L1, L2):- 
	perm(L1, L2), sortGrade(L2). 

sortGrade([]):- 
	write('\n\tNo records to display\n').

sortGrade([_]).

sortGrade([[A,B,C], [X,Y,Z] | T]) :- 
	Z < C, sortGrade([[X,Y,Z] | T]).

%Name
naive_sortName(L1, L2):- 
	perm(L1, L2), sortName(L2). 

sortName([]):- 
	write('\n\tNo records to display\n').

sortName([_]).

sortName([[A | [B | C]], [X | [Y | Z]] | T]) :- 
	B @=< Y, sortName([[X | [Y,Z]] | T]).
