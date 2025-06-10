input = ")))()"

def problem2(input):
    left_needed = 0   # 닫히지 않은 '('의 개수
    to_add = 0        # 추가해야 할 괄호 수

    for char in input:
        if char == '(':
            left_needed += 1
        elif char == ')':
            if left_needed > 0:
                left_needed -= 1  # 올바르게 닫힘
            else:
                to_add += 1       # '('가 부족하므로 하나 추가해야 함

    to_add += left_needed  # 남은 '('는 ')'로 닫아줘야 함

    return to_add

result = problem2(input)

assert result == 3
print("정답입니다.")
