package main

import "fmt"

func fun1() {
   /* 局部变量定义 */
   var a int = 100;
 
   /* 判断布尔表达式 */
   if a < 20 {
       /* 如果条件为 true 则执行以下语句 */
       fmt.Printf("a 小于 20\n" );
   } else {
       /* 如果条件为 false 则执行以下语句 */
       fmt.Printf("a 不小于 20\n" );
   }
   fmt.Printf("a 的值为 : %d\n", a);
}

func fun2() {
   /* 定义局部变量 */
   var grade string = "B"
   var marks int = 90

   switch marks {
      case 90: grade = "A"
      case 80: grade = "B"
      case 50,60,70 : grade = "C"
      default: grade = "D"  
   }

   switch {
      case grade == "A" :
         fmt.Printf("优秀!\n" )    
      case grade == "B", grade == "C" :
         fmt.Printf("良好\n" )      
      case grade == "D" :
         fmt.Printf("及格\n" )      
      case grade == "F":
         fmt.Printf("不及格\n" )
      default:
         fmt.Printf("差\n" );
   }
   fmt.Printf("你的等级是 %s\n", grade );     
}

func fun3() {
   c1 := make(chan string)
   c2 := make(chan string)

   go func() {
       time.Sleep(1 * time.Second)
       c1 <- "one"
   }()
   go func() {
       time.Sleep(2 * time.Second)
       c2 <- "two"
   }()

   for i := 0; i < 2; i++ {
       select {
       case msg1 := <-c1:
           fmt.Println("received", msg1)
       case msg2 := <-c2:
           fmt.Println("received", msg2)
       }
   }  
}

func main() {
   fun1()
}