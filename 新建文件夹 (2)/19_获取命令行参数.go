package main

import (
	"fmt"
	"os"
)

func main() {
	//获取用户的传递的参数，以字符串方式
	list := os.Args
	n := len(list)
	fmt.Println("n=", n)

	for i, data := range list {
		fmt.Printf("list[%d]=%s\n", i, data)
	}

}
