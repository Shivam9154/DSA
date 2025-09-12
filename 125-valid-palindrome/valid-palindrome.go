func isValid(ch rune) bool {
	return unicode.IsLetter(ch) || unicode.IsDigit(ch)
}

func convertLower(ch rune) rune {
	return unicode.ToLower(ch)
}

func isPalindrome(s string) bool {
	runes := []rune(s)
	return helper(runes, 0, len(runes)-1)
}

func helper(runes []rune, left int, right int) bool{
    if left>=right{
        return true
    }
    if !isValid(runes[left]){
        return helper(runes,left+1,right);
    }
    if !isValid(runes[right]){
        return helper(runes,left,right-1);
    }
    if convertLower(runes[left])!=convertLower(runes[right]){
        return false;
    }
    return helper(runes,left+1,right-1);       
}