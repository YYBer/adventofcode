const fs = require('fs');

function getFirstNumber(input, num) {
    let a = 0;
    let b = 0;
    let i;
    let j;
    let pos;
    for (i = 0; i < input.length; ++i) {
        if (input[i] <= '9' && input[i] >= '0') {
            a = input[i];
            break;
        }
    }
    let tmp = 999;
    for (j = 1; j < 10; ++j) {
        pos = input.indexOf(num[j]);
        if (pos !== -1 && pos < tmp) {
            b = j;
            tmp = pos;
        }
    }
    if (tmp < i)
        a = b;
    return a;
}

function getLastNumber(input, num) {
    let c = 0;
    let d = 0;
    let i;
    let j;
    let pos;
    for (i = input.length - 1; i >= 0; --i) {
        if (input[i] <= '9' && input[i] >= '0') {
            c = input[i];
            break;
        }
    }
    let tmp = 0;
    for (j = 1; j < 10; ++j) {
        pos = input.lastIndexOf(num[j]);
        if (pos !== -1 && pos > tmp) {
            d = j;
            tmp = pos;
        }
    }
    if (tmp > i)
        c = d;
    return c;
}

const num = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"];
let sum = 0;
let result = 0;
let input = "";
const data = fs.readFileSync('infile.txt', 'utf8');
const lines = data.split('\n');
for (let i = 0; i < lines.length; i++) {
    input = lines[i];
    const a = parseInt(getFirstNumber(input, num));
    const c = parseInt(getLastNumber(input, num));
    sum = 10*a + c;
    console.log("sum " + sum);
    result += sum;
}
console.log(result);