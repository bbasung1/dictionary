import requests
url='https://api.dictionaryapi.dev/api/v2/entries/en/'
MAX=9
N=0
M=0
arr=[None]*MAX
visited=[0]*MAX
word=[]
def func(cnt,k):
    if(cnt==M):
        tmp=[]
        for i in range(M):
            # print(k[arr[i]-1],end="")
            tmp.append(k[arr[i]-1])
        # print("n")
        j=0
        for i in pos:
            tmp.insert(i-1,ltr[j])
            j+=1
        veri=''.join(tmp)
        print(veri+"맞는 단어인지 확인중...")
        res=requests.get(url+veri)
        if(res.text[1]=='{'):
            print("사전에 있는 단어 입니다!")
            word.append(veri)
        else:
            print("없는 단어 입니다.")
        #print(res.text)
        #word.append(''.join(tmp))
    for i in range(1,N+1):
        if not visited[i]:
            visited[i]=1
            arr[cnt]=i
            func(cnt+1,k)
            visited[i]=0
k=input("이미 나온 글자들을 제외하고, 제시낱말들을 이어 쓰세요: ")
# N,M=map(int,input("").split())
N=len(k)
M=int(input("비어있는 칸의 수를 입력하세요: "))
fn=int(input("채워져 있는 칸 수를 입력하세요: "))
pos=[None]*fn
ltr=[None]*fn
X=N+M
for i in range(fn):
    pos[i]=int(input("채워져있는 자리의 위치를 입력하세요: "))
    ltr[i]=input("채워져 있는 글자를 입력하세요: ")
ltr=list(ltr)
print(type(ltr))
func(0,k)
print("확인된 단어")
print(word)