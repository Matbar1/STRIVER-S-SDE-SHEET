class Solution {
public:
    void floodFillHelper(std::vector<std::vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
    int numRows = image.size();
    int numCols = image[0].size();

    // Base cases for recursion
    if (sr < 0 || sr >= numRows || sc < 0 || sc >= numCols || image[sr][sc] != oldColor || image[sr][sc] == newColor)
        return;

    // Update the color at the current position
    image[sr][sc] = newColor;

    // Recursive calls for neighboring pixels
    floodFillHelper(image, sr - 1, sc, newColor, oldColor); // Up
    floodFillHelper(image, sr + 1, sc, newColor, oldColor); // Down
    floodFillHelper(image, sr, sc - 1, newColor, oldColor); // Left
    floodFillHelper(image, sr, sc + 1, newColor, oldColor); // Right
}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
    if (image.empty() || image[sr][sc] == newColor)
        return image;

    int oldColor = image[sr][sc];
    floodFillHelper(image, sr, sc, newColor, oldColor);

    return image;
}
};