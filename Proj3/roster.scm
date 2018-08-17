;;Abygail Stiekman;;
;;COP4020 Project 3;;
;;03/31/2017;;



(define read-3-items
	(lambda (n lst)
		(cond ((= n 2) (begin
						(display "\tGrade: ")
						(list (car lst) (car (cdr lst )) (read-line))
						))
			  ((= n 1) (begin
						(display "\tStudent name: ")
						(read-3-items 2 (list (car lst) (read-line)))
						))
			  ((= n 0) (begin
						(display "\tStudent ID: ")
						(read-3-items 1 (list (read-line)))
						))
		)
	)
)

(define delete-record 
	(lambda (item lst)
		(cond ((equal? item (car (car lst))) 
			(begin  
			(display "\n\tStudent with ID ")
			(display (car (car lst)))
			(display " deleted.\n")
			(cdr lst)
			)
         )
		((equal? item (car(cdr(car lst)))) 
			(begin
			(display "\n\tStudent with name ")
			(display (car (cdr(car lst))))
			(display " deleted.\n")
			(cdr lst)
			)
		)
		(else (cons (car lst) (delete-record item (cdr lst))))
      )
	)
)

(define display-record
	(lambda (record n) 
		(begin
			(display "\n\tNo." )
			(display n)
			(display ": ID = ")
			(display (car record))
			(display ", Name = " )
			(display (car (cdr record)))
			(display ", Grade = " )
			(display (cadr (cdr record)))
		)
	)
)

(define display-roster
	(lambda (roster n)
		(cond ((null? roster) (display "No records to display"))
			(else
				(begin
					(display-record (car roster) n)
					(display-roster (cdr roster) (+ n 1))
				)
			)
		)	
	)
)

(define remove
	(lambda (roster record)
		(cond ((null? roster) '())
			((equal? (car roster) record) (cdr roster))
			(else (cons (car roster) (remove (cdr roster) record)))
		)
	)
)

(define smallest
	(lambda (roster item)
		(cond ((null? roster) item)
			((< (string->number (car(car roster))) (string->number (car item))) (smallest (cdr roster) (car roster)))
			(else (smallest (cdr roster) item))
		)		
	)
)

(define sort
	(lambda (roster)
		(if (null? roster) '()
			(cons (smallest roster (car roster))
				(sort (remove roster (smallest roster (car roster))))
			)
		)
	)
)

(define display-student-info
	(lambda (item lst)
		(cond ((equal? item (car (car lst))) 
        	(begin
        		(display "\tID=")
        	    (display (car (car lst)))
        		(display ", Name=")
        	    (display (car (cdr (car lst))))
        	    (display ", Grade=")
        	    (display (car (cdr (cdr (car lst)))))
        	    (display "\n")
			))
			((equal? item (car (cdr(car lst))))
				(begin
          		(display "\tID=")
        	    (display (car (car lst)))
        		(display ", Name=")
        	    (display (car (cdr (car lst))))
        	    (display ", Grade=")
        	    (display (car (cdr (cdr (car lst)))))
        	    (display "\n")
				)
			)
		(else (cons (car lst) (display-student-info item (cdr lst))))
		)
 	)
)

(define performtask
	(lambda (n roster) 
		(cond ((= n 0) (begin
                    (display "\n\tRoster reset (now empty). \n\n")
                    (menu '())
                    ))
			((= n 1) (begin
                    (display "\n\tLoad roster from file: ")
					 (menu (read (open-input-file(read-line))))
                   ))
			((= n 2) (begin
					(display "\n\tStore roster to file: ")
					(let((port (open-output-file (read-line))))
					(write roster port)
					(close-output-port port))
					(display "\n")
					(menu roster)
					))
			((= n 3) (begin
					(display "\n\tDisplaying roster, sorted by ID: ")
					(display-roster (sort roster) 1)
					(display "\n")
					(menu roster)
					))
			((= n 4) (begin
                    (display "\n\tEnter a student name or ID: ")
                    (display-student-info (read-line) roster)
					(display "\n")
					(menu roster)
                    ))
			((= n 5) (begin
					(display "\n\tAdd a student to roster: \n")
					(menu (cons(read-3-items 0 '()) roster))
					(menu roster)
					))
			((= n 6) (begin
                    (display "\n\tEnter a student name or ID: ")
                    (menu(delete-record (read-line) roster))
                    (display "\n")
                    ))
						  
			((= n 7) (begin
                    (display "\n\tGoodbye!\n")
                    #t
                    ))					
			(else (begin
                    (display "\n\ttask no. ")
                    (display n)
                    (display " does not exist.\n\n")
                    (menu roster)
                  )
            )
		)
	)
)

(define menu
  (lambda (roster)
     (begin
		(display "\n\tClass roster management system\n")
        (display "\t==============================\n")
        (display "\t   MENU\n")
        (display "\t==============================\n")
        (display "\t0. Reset roster\n")
        (display "\t1. Load roster from file\n")
		(display "\t2. Store roster to file\n")
		(display "\t3. Display roster sorted by ID\n")
		(display "\t4. Display student info\n")
		(display "\t5. Add a student to roster\n")
		(display "\t6. Remove a student from roster\n")
        (display "\t7. Exit\n\n")
        (display "\tEnter your choice: ")
        (performtask (read) roster)
      )
   )
)