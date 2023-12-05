const fs = require('fs');

function getNumber(cubes, color, pos) {
    const numsub = cubes.substring(0, pos);
    const i = numsub.length;
    if (i === 1) {
        return (numsub.charCodeAt(0) - 48);
    } else {
        if (numsub.charCodeAt(i - 2) <= 57 && numsub.charCodeAt(i - 2) >= 48) {
            return (10 * (numsub.charCodeAt(i - 2) - 48) + numsub.charCodeAt(i - 1) - 48);
        } else {
            return (numsub.charCodeAt(i - 1) - 48);
        }
    }
}

function fewestNumberCube(input) {
    const pos = input.indexOf(':');
    let cubes = '';
    if (pos !== -1) {
        cubes = input.substring(pos + 2);
    }
    let numr = 1;
    let numg = 1;
    let numb = 1;
    let num;
    for (let i = 0; i < cubes.length; ++i) {
        if (cubes[i] === 'r' && cubes[i - 1] === ' ') {
            num = getNumber(cubes, "red", i - 1);
            if (num > numr) {
                numr = num;
            }
        } else if (cubes[i] === 'g') {
            num = getNumber(cubes, "green", i - 1);
            if (num > numg) {
                numg = num;
            }
        } else if (cubes[i] === 'b') {
            num = getNumber(cubes, "blue", i - 1);
            if (num > numb) {
                numb = num;
            }
        }
    }
    return numr * numg * numb;
}

let input = "";
let sum = 0;
let gameID = 0;
const data = fs.readFileSync("input.txt", "utf8");
const lines = data.split("\n");
lines.forEach((line) => {
    gameID++;
    sum += fewestNumberCube(line);
});
console.log("sum: " + sum);


