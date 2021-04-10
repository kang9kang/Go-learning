package main

import "fmt"

func Myfunc() (result int) {
	result = 666
	return
}

func main() {
	var a int
	a = Myfunc()
	fmt.Println("a=", a)

	b := Myfunc()
	fmt.Println("b=", b)
}
