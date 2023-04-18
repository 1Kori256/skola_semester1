class Rect:
    def __init__(self, x1, y1, x2, y2):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2

    def __repr__(self):
        return f"Rect({self.x1},{self.y1},{self.x2},{self.y2})"

    def perimeter(self):
        return 2 * (self.x2 - self.x1) + 2 * (self.y2 - self.y1)
    
    def area(self):
        return (self.x2 - self.x1) * (self.y2 - self.y1)

    def __eq__(self, other):
        if self.x1 == other.x1 and self.x2 == other.x2 and self.y1 == other.y1 and self.y2 == other.y2:
            return True
        else:
            return False

    def __contains__(self, other):
        if self.x1 <= other.x1 and self.x2 >= other.x2 and self.y1 <= other.y1 and self.y2 >= other.y2:
            return True
        else:
            return False

    def __and__(self, other):
        new_x1 = max(self.x1, other.x1)
        new_x2 = min(self.x2, other.x2)
        new_y1 = max(self.y1, other.y1)
        new_y2 = min(self.y2, other.y2)
        if new_x1 > new_x2 or new_y1 > new_y2:
            return Rect(0, 0, 0, 0)
        else:
            return Rect(new_x1, new_y1, new_x2, new_y2)