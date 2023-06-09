# oostubs
All code for new tasks cannot be implemented directly on the main branch and requires a new branch. After making sure the code runs without errors, it can be merged into the main branch.
## Hint for Git
### How to get update from official repo
```
git remote add upstream https://os.inf.tu-dresden.de/Studium/OSC/SS2023/oostubs.git
git pull upstream main
git push
```
### How to switch branch
```
git branch
git checkout ${branch_name}
```
### How to push new codes
```
git add .
git commit -m "{commit}"
git push
```
### How to merge the branch
 merging A branch into B branch
```
git checkout B
git merge A
git push
```
