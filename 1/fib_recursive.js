const fib = (n) => {
  if (n == 0 || n == 1) {
    return n;
  }
  return fib(n - 1) + fib(n - 2);
};

const num = 38;

for (let i = 0; i <= num; i++) {
  // fib(i);
  console.log(`fib(${i}) = `, fib(i));
}
// console.log(obj);

// takes 5.934 seconds to calculate till fib(38)
