package main

import "fmt"

func main() {
	a := 10
	str := "mike"
	func() {
		//闭包是以引用的方式捕获外部变量
		a = 666
		str = "go"
		fmt.Printf("内部：a=%d,str=%s\n", a, str)
	}()
	fmt.Printf("外部：a=%d,str=%s\n", a, str)
}
