package main

import "fmt"

func Myfunc(a, b int) (max, min int) {
	if a > b {
		max = a
		min = b
	} else {
		min = a
		max = b
	}
	return
}

func main() {
	max, min := Myfunc(10, 20)
	fmt.Printf("max=%d,min=%d\n", max, min)
}
