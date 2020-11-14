// algorithm:
// Shift 'n-1' disks from 'A' to 'B'.
// Shift last disk from 'A' to 'C'.
// Shift 'n-1' disks from 'B' to 'C'.

const TowerOfHanoi = (n, from_rod, to_rod, aux_rod) => {
  if (n <= 1) {
    console.log("Move disk " + n + " from " + from_rod + " to " + to_rod);
    return;
  }
  TowerOfHanoi(n-1,from_rod,aux_rod,to_rod);
  console.log("Move disk " + n + " from " + from_rod + " to here" + to_rod);
  TowerOfHanoi(n-1,aux_rod,to_rod, from_rod);
};

let n = 4;
TowerOfHanoi(n, "A", "C", "B");
