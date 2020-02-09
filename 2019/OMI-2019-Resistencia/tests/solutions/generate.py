from collections import deque

def pm(number, steps = 0):
	if len(number) == 1:
		return steps;
	else:
		r = 1;
		for c in number:
			r *= int(c);
		return pm(str(r), steps + 1)

chars = ['2','3','5','6','7','8','9']
queue = deque(chars)
def amplitud(max):
	m = 1
	while len(queue) > 0:
		x = queue.popleft();
		r = pm(x)
		if r > m:
			print (x, r)
			m = r

		lastchar = x[-1:]
		if len(x) < max:
			for ch in chars:
				if ch >= lastchar:
					queue.append(x+ch)

amplitud(17)

