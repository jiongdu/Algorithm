package main

import "fmt"

var oneDone = make(chan bool)
var twoDone = make(chan bool)

func first() {
	fmt.Println("one")
	oneDone <- true
}

func second() {
	<-oneDone
	fmt.Println("two")
	twoDone <- true
}

func third() {
	<-twoDone
	fmt.Println("three")
}

func main() {
	go second()
	go third()
	go first()

	fmt.Scanln()
}
