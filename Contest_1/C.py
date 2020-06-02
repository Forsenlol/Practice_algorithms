# #!/usr/bin/env python3
 
 
def main():
    text = []
    while True:
        try:
            text.append(input())
        except EOFError:
            break
    text2 = ''.join(text)
    text = text2.split(' ')
    i = 0
    for i, elem in enumerate(text):
        if text[i] == '*' or text[i] == '+' or text[i] == '-':
            text[i] = text[i]
        else:
            text[i] = int(elem)
    i = 0
    while len(text) != 1:
        if text[i] == '*':
            text[i - 2] *= text[i - 1]
            del text[i]
            del text[i - 1]
            i -= 1
        elif text[i] == '-':
            text[i - 2] -= text[i - 1]
            del text[i]
            del text[i - 1]
            i -= 1
        elif text[i] == '+':
            text[i - 2] += text[i - 1]
            del text[i]
            del text[i - 1]
            i -= 1
        else:
            i += 1
    print(text[0])
 
 
if __name__=="__main__":
    main()