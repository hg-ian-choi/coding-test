/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function (s, numRows) {
  // can not zigzeg
  if (numRows === 1 || s.length < numRows) {
    return s;
  }

  // can zigzeg

  // create array[][]
  let sArray = new Array();
  for (let i = 0; i < numRows; i++) {
    sArray[i] = new Array();
  }

  // units
  let zigzegDirectionChanged = false;
  const rowContainWords = numRows + numRows - 2;
};
