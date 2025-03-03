def print_zigzag(s: str, numRows: int) -> None:
    if numRows == 1 or numRows >= len(s):
        print(s)
        return

    rows = [""] * min(numRows, len(s))
    curRow = 0
    goingDown = False

    for char in s:
        rows[curRow] += char
        if curRow == 0 or curRow == numRows - 1:
            goingDown = not goingDown
        curRow += 1 if goingDown else -1

    for row in rows:
        print(row)

# Example usage
s = "PAYPALISHIRING"
numRows = 8
print_zigzag(s, numRows)
