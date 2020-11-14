let n = 200,
  i = 0;
let a = 1,
  b = 1,
  c;

while (i < n - 2) {
  c = a + b;
  console.log(c, " ");
  a = b;
  b = c;
  i++;
}
