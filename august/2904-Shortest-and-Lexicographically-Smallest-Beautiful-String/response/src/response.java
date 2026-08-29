class Solution {
	public String shortestBeautifulSubstring(String s, int k) {
		int totalval = 0;

		// Checking if total lexiographical values minus zero add up to k.
		// Otherwise k will be unreachable if total lexiographical values minus 
		// zero can't reach k
		for (int i = 0; i < s.length(); i++) {
		totalval += s.charAt(i) - '0';
		}
		if (totalval < k) return "";
		
		// `result` will be our String that we index over
		String result = s;
		
		// left index of sliding window
		int left_idx = 0;
		
		// this will be the count to keep track of within each window
		int count = 0;

		for ( int right = 0; right < s.length(); right++) {
			count += s.charAt(right) - '0';		
			
			if (count == k || left == 0) {
				count -= s.charAt(left++);
	}
}
