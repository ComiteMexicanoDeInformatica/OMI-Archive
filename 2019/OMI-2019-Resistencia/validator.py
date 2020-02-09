import math

def pm(number, steps = 0):
	if len(number) == 1:
		return steps;
	else:
		r = 1;
		for c in number:
			r *= int(c);
		return pm(str(r), steps + 1)

answers = {
	0: "0",
	1: "10",
	2: "25",
	3: "39",
	4: "77",
	5: "679",
	6: "6788",
	7: "68889",
	8: "2677889",
	9: "26888999",
	10: "3778888999",
	11: "277777788888899"
}

points = {
	-1: 1,
	0: 1,
	1: 3,
	2: 6,
	3: 10,
	4: 14,
	5: 18,
	6: 22,
	7: 26,
	8: 30,
	9: 34,
	10: 60,
	11: 100
}

contestant = (raw_input().strip())
if str.isdigit(contestant):
	p = pm(contestant);
	if answers[p] == contestant:
		score = points[p]
	else:
		score = math.trunc((points[p]+points[p-1])/2)
else:
	score = 0

print(score/100.0)
