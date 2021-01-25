package main

import (
	"fmt"
	"os"
)

var matrix [5][5]string

func main() {
	var done string
	fmt.Println("Tic Tac Toe!")
	fmt.Println("play with Comput3r")

	done = " "
	initMatrix()
	for done == " " {
		displayMatrix()
		getPlayerMove()
		done = check()
		if done != " " {
			break
		}
		getComputerMove()
		done = check()

	}
	if done == "x" {
		fmt.Println("You Won!")
	}
	if done == "o" {
		fmt.Println("Computer Won!")
	}
	displayMatrix()

}

func initMatrix() {
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			matrix[i][j] = " "
		}
	}
}

func displayMatrix() {
	for t := 0; t < 3; t++ {
		fmt.Printf(" %s | %s | %s \n", matrix[t][0], matrix[t][1], matrix[t][2])
		if t != 2 {
			fmt.Printf("---|---|---\n")
		}
	}
}

func getPlayerMove() {
	var x, y int
	fmt.Println("Enter X,Y coordinates for your move: ")
	fmt.Scanln(&x)
	fmt.Scanln(&y)
	x--
	y--

	if matrix[x][y] == " " {
		matrix[x][y] = "x"
	} else {
		fmt.Println("Invalid move try again!")
		getPlayerMove()
	}
}

func check() string {

	// check row
	for i := 0; i < 3; i++ {
		if matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2] {
			return matrix[i][0]
		}
	}
	// check column
	for i := 0; i < 3; i++ {
		if matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i] {
			return matrix[0][i]
		}
	}
	// check diagonal
	for i := 0; i < 3; i++ {
		if matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2] {
			return matrix[0][0]
		}
		if matrix[0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1] {
			return matrix[0][1]
		}
		if matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0] {
			return matrix[0][2]
		}
	}
	return " "
}

func getComputerMove() {
	var i, j int
	for i = 0; i < 3; i++ {
		for j = 0; j < 3; j++ {
			if matrix[i][j] == " " {
				break
			}
		}
		if matrix[i][j] == " " {
			break
		}
	}
	if i*j == 9 {
		fmt.Println("draw")
		os.Exit(1)
	} else {
		matrix[i][j] = "o"
	}
}
