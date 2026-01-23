package main

func lemonadeChange(arr []int) bool {
	n := len(arr)
	fives, tens := 0, 0
	// Do we care about 20s .. ?

	for i := 0; i < n; i++ {
		if arr[i] == 5 {
			fives++
		} else if arr[i] == 10 {
			if fives > 0 {
				fives--
				tens++
			} else {
				return false
			}
		} else if arr[i] == 20 {
			// 15 := either 3 fives or 1 ten + 1 five
			// We will go with (1 ten + 1 five) first as ten can't be used
			// anywhere else .. ?
			if tens > 0 && fives > 0 {
				tens--
				fives--
			} else if fives >= 3 {
				fives -= 3
			} else {
				return false
			}
		}
		// fmt.Println("cur, fives, tens : ", arr[i], fives, tens)

	}

	return true

}
