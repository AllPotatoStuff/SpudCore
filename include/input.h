#ifndef INPUT_H__
#define INPUT_H__

class Input {
private:
public:
  Input();

  bool isKeyDown(int key) const;
  bool isKeyPressed(int key) const;
  bool isKeyReleased(int key) const;
};

#endif // INPUT_H__