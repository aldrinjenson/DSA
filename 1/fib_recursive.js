let obj = {
  0: 0,
  1: 1,
};
const fib = (n) => {
  if (!obj.hasOwnProperty(n)) {
    obj[n] = fib(n - 1) + fib(n - 2);
  }
  return obj[n];
};

const num = 1000;

for (let i = 0; i < num; i++) {
  console.log(fib(i), " ");
}

console.log(obj)