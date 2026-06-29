*Este proyecto ha sido creado como parte del currículo de 42 por durisosa.*
![License](https://img.shields.io/badge/license-MIT-blue)
![Version](https://img.shields.io/badge/version-1.0.0-green)   
![GitHub stars](https://img.shields.io/github/stars/dmsosa/REPO?style=social)

# Contributions from each member

Update for June 29th, as passing the s_pushswap struct to each function was too much work, it was removed and the struct s_stack is now added more members. All of this was necessary to count the total number of moves and store other data.

# Description.

//how to parse the args? or me the most straightforward and simple solution is
//to take the args, split if necessary, if not, just traverse each arg and convert to nbr with atol
//if there is a syntax error, throw error.
//ft_error sounds simple
//but can I do a simple program that takes the args, create two stacks, and simply push all numnbers on to b and then rotate? and print the movement and the stacks at the end

# Instructions

1. Clone the repo with `git clone`;
2. This project has no Makefile, so only compiling the main will make you able to test it.
3. Copy this command to compile the mandatory part `gcc -Wall -Wextra -Werror -Wl,--wrap=malloc -g get_next_line.c get_next_line_utils.c main.c -o a.out`
4. Copy this command to compile the bonus `gcc -Wall -Wextra -Werror -Wl,--wrap=malloc -g get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o a.out`
5. Execute the binary ./a.out

# Resources

The Manual ('man' command) of the Unix operating system, Google and Stack Overflow questions were used as the main sources of information.

Other support materials have been the GitHub repositories of other cursus students.

Students that inspired me a lot:

[youssef-be](https://github.com/youssef-benchaaboun)
[jdecorte-be](https://github.com/jdecorte-be)
[mcombeau](https://github.com/mcombeau)
[suspectedoceano](https://github.com/suspectedoceano)


## IA Usage:

I used the IA as a support to speed up the following tasks: 

a. Add shields to the README.md.
b. Filter best Stack Overflow answers to my questions
c. Summary information available on the internet
d. Investigating which smaller skills were needed to successfully understand this topic.

## About the program

### Question 1:
Can I create a program that receives the following command line args and prints the resulting stack in the console?

./push_swap "             4 --medium   3  2  444444  567 88687 --simple"  88687 --simple $(cat agv.txt)

#### To Do 
- selector = argv[buscar if startwith --]
- check env vars 
- "             4 --medium   3  2  444444  567 88687 --simple"  88687 --simple $(cat agv.txt)
 after ft_strjoin_always_separated: 
 "             4  --medium    3   2   444444 567 88687 --simple 88687 $(resultofcat)"  
 after split: "
 4,
 --medium,
 3,
 2,
 444444,
 567,
 88687,
 --simple,
 88687,
 $(resultofcat)
(null)
" 

#### Rules while parsing:
1. 	//only accept "valid_selector" values, otherwise error
	//no more than one selector, otherwise throw error
	//if no selector is found, null
2. - only valid digits once I started parsing digits 

- join first, split after 
- receive selector that starts with -- (valid values are simple medium complex or adaptative, else error)
- if selector is adaptative, use the compute disorder function to choose an algorithm
- 
- Deberá quedar documentado en el repositorio (por ejemplo, en el archivo README.md)
- la justificación de los valores límite (umbrales) que definen cada nivel de desorden,
- una descripción de las técnicas internas empleadas en cada caso y un breve análisis de complejidad -indicando las cotas superiores de espacio y tiempo- dentro del
- modelo de Push_swap.
- 
- 
- sorting logic:
- binary tree for sorting
# EXPLAIN IT AS IF I'M 5 YEARS OLD:

# To Do 
- CHECK THAT NUMBERS ARE NOT DUPLICATED
- CAN MY PROGRAM SORT A STACK OF 2? 3? 4 AND 5 MANUALLY?
