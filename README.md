# Sub-C-Interpreter

A Sub C language interpreter able to execute C-written instructions both by C text file and by console real time input. The interpreter is able to recognize errors (lexical/syntax/semantic/logic errors) reporting them and to arise warnings to improve the user experience.

The lexical analyzer was generated using **Flex** (the scanner generator) where regular expressions was used to describe the token patterns.
The syntax analyzer was generated using **Bison** (the parser generator): it builds the parse tree using a bottom-up approach. The sub-C language syntax was developed by scratch.
The semantic analysis phase uses the **'syntax-directed'** approach and builds the intermediate representation: an Abstract Syntax Tree (AST).
The interpretation phase uses the generated intermediate representation to execute the C instructions.

The Interpreter works with a subset of C language instructions and data structures.


**If you publish any work which uses the code stored in this project, please cite the following creator:** <br/>
Alberto Carlo  Maria Mancino

**Developer** <br/>
Alberto Carlo Maria Mancino <br/>

**Contacts** <br/>
I'm happy to help you with any question. Please contact me on my mail: <br/>
alberto.mancino94@gmail.com <br/>
<br/>
