const fs = require('fs');

function getNumber(cubes, color, pos) {
    const numsub = cubes.substring(0, pos);
    const i = numsub.length;
    if (i === 1) {
        return parseInt(numsub[0]);
    } else {
        if (numsub[i - 2] <= '9' && numsub[i - 2] >= '0') {
            return 10 * (parseInt(numsub[i - 2])) + parseInt(numsub[i - 1]);
        } else {
            return parseInt(numsub[i - 1]);
        }
    }
}

function validGame(input) {
    const pos = input.indexOf(':');
    let cubes = '';
    if (pos !== -1) {
        cubes = input.substring(pos + 2);
    }
    let num = -1;
    for (let i = 0; i < cubes.length; ++i) {
        if (cubes[i] === 'r' && cubes[i - 1] === ' ') {
            num = getNumber(cubes, "red", i - 1);
            if (num > 12) {
                return false;
            }
        } else if (cubes[i] === 'g') {
            num = getNumber(cubes, "green", i - 1);
            if (num > 13) {
                return false;
            }
        } else if (cubes[i] === 'b') {
            num = getNumber(cubes, "blue", i - 1);
            if (num > 14) {
                return false;
            }
        }
    }
    return true;
}

fs.readFile('input.txt', 'utf8', (err, data) => {
    if (err) {
        console.error(err);
        return;
    }
    const lines = data.split('\n');
    let sum = 0;
    let gameID = 0;
    lines.forEach((line) => {
        gameID += 1;
        if (validGame(line)) {
            console.log(`line ${gameID} OK!`);
            sum += gameID;
        }
    });
    console.log(`sum: ${sum}`);
});


