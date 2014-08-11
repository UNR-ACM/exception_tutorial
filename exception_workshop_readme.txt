%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

	An Intro to Exceptions in C++
	(Warning: may contain Java flavoring)
	https://github.com/UNR-ACM/git_tutorial

	Presented by: Terence Henriod, UNR ACM
	Content by:   Many others who are not explicitly listed

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	Step 0: Gather your materials for this workshop
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

You will need:

	A text editor (preferably a good one like SublimeText or one that's part
	of an IDE, although a default TextEditor, like gedit, is fine)

	A C++ compiler, like g++ (if you want to compile/run code)
	
	A web browser (preferably Chrome) with a tab open to
	http://docs.oracle.com/javase/tutorial/essential/exceptions/advantages.html
	(I know, it's a Java site, but it's basically pseudo-code and it's
	very informative)

	A web browser (preferably Chrome) with a tab open to the code at
<github>


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	Step 1: Get the materials from github
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

If you have git installed, create a repository and pull the code with the
following terminal commands (edit as necessary):


Otherwise, copy and paste the code on github as necessary.


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	Step 2: Read the Java article on exceptions
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

This should demonstrate why exceptions are a good thing, and not something
taboo or scary.

No need to memorize, just get a basic since of what exceptions do and
how they improve code. This article is not meant to teach you C++ syntax.


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	Step 3: Some notes on C++ exception syntax
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Read this section, but don't worry if you don't get it the first time.
Refer back to this section as necessary.

In general, the concept of exceptions can be summarized as:
try...throw...catch. We try some action that might throw an exception, an
action may throw an exception or we may choose to throw one if things are in
a bad state, then we catch any exceptions that arise and take appropriate
action. The cliche example looks like:

~~~~~~~~~
	try {

		...some arbitrary code...

		if (badThingHappened) {
			throw exception();
		}

		...other code if things went fine...

	} catch (exception& e) {

		cout << e.errorMessage() << endl;

		...or any other code to remedy the situation...
	
	}

		...other code that executes if the catch block was used...
~~~~~~~~~

The "try" indicates to the compiler that you are aware an exception can
come out of the code inside. If an exception is "thrown", the rest of the
code in the block/function/program is skipped until the exception is caught.
All objects from inside the try block are destroyed though, so as your
classes become more complex, this may become more relevant when writing
destructor functions.
Once an appropriate "catch" block is found, the code inside that block runs,
and "normal" program execution is resumed. Notice that the catch block
essentially defines a variable of a given exception type. That variable
lives ONLY in the scope of the catch block.

Notice that the exception variable of the catch block has a '&' operator
in its definition. This makes it a reference variable which, among other
things, enables inheritance/polymorphism properties. It's a good habit
to be in to write your catches with '&' pretty much always.

Do note that exceptions are variables like any other class/complex
object, so you can construct them and act on them before throwing them.
While they are commonly constructed as they are being thrown, if
it is not simple to initialize them, create and initialize them before
using the "throw" command.


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	Step 4: Let's break out the code!
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Ready to see some exceptions in action? Compile and run the workshop code.

Consider the warm-up function.
It fails pretty ungracefully right? What if you wanted your program to
recover from something like this? Like in this situation, you might want to
just try requesting less memory and continuing on. A simple solution to a
simple problem. Uncomment some code and make any changes you want to, and
see how much better your program gets.


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	Step 5: Hello Exceptions!
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

This is two part: first with the STL basic exception, then with our own
custom exception (similar to the Java basic exception).

Uncomment the "Hello Exceptions" block in the main function.

First fill in some code where you try...throw...catch a basic exception.
The STL exception is in the std namespace, and has a no-argument constructor.
Compile and run to make sure you made it work.

Now try it with the derived exception created in workshop_exceptions.hpp.
try...throw...catch one of these using a simple message like
"Hello Exceptions!"
Compile and run to make sure you made it work.


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	Step 6: Catching different kinds of exceptions
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Many different exceptions can come out of a try block, and depending on what
kind of exception it is, we might want to take different actions or access
different properties of the exception that is caught. For this reason, it
is possible to specify multiple catch blocks for a single try block.

Uncomment the different exceptions block in the main function.

Fill in the missing parts of the function using the further derived
exceptions from the header file. Fill in the missing code in the two derived
exceptions specified in exception_workshop.hpp.
Compile and run to make sure you made it work.

Did you notice that there was a warning when compiling? Your program still
ran, but it wasn't as good as could be. This is a lesson in inheritance.
Since all 3 types of exceptions were some form of WorkshopStdExceptionWrapper,
they all get caught by the first catch block, and we don't get to take
advantage of the special features of the more specific exception types.
Rearrange the catch blocks to a more logical order and get rid of the warning.
Compile and run to make sure you made it work.

Do note though, there may be times when you don't want to take specific
actions for specific types of exceptions, and the same action will work for
all exceptions for a particular base exception type (i.e. use ONE catch
block).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	Step 7: Making and using your own exceptions!
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Remember how exceptions are "thrown up the stack"? That means that if you don't
catch an exception, it goes to the function that called it, and up and up
until it's finally caught. If the exception is never caught, the program
crashes.

YOU MAY NEED TO TAKE THIS ONE HOME TO COMPLETE IT

Uncomment the remaining code block.

Put in code of your choosing in both code files. Make your own exception(s),
and make your own situation. Try catching the exception you throw in the
main function. Even try nexting functions to see how many functions you can
throw up through. Do any other experiments on exceptions you want!
Compile and run to make sure you made it work.


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	Step 8: Parting words
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

If you are not familiar with the properties of inheritance, now is a good
time to start, it is particularly useful in the domain of exceptions. Deriving
exceptions from the STL one is nice for people who may use your code later
because they won't have to look up all the details of your exception,
they can just catch any std::exception and act appropriately, especially if
you properly overload the what() method.

Take care when specifying things with the throw() clause. It is good for
readability and "code contracts," but most of the time it causes hassle
many people don't want to deal with.

Don't lose faith if you don't get opportunities to use exceptions in courses -
create the opportunities when you can.


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	Check these out too!
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Another brief tutorial on excpetions:
http://www.cplusplus.com/doc/tutorial/exceptions/

Java Exceptions (great for concept):
http://docs.oracle.com/javase/tutorial/essential/exceptions/

This should be full of good info:
http://stackoverflow.com/questions/4506369/when-and-how-should-i-use-exception-handling
