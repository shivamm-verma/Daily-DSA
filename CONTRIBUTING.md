# How to create a fresh ISSUE?

# How to create a PR (Pull Request) for this? 
- For Code change & No code change both.

###  **Create a PR from an Issue**

1. **Fork & Clone** the repo.
2. **Create a new branch**:
```sh
   git checkout -b fix-issue-12
```
4. **Commit & Push**:
```sh
   git add .
   git commit -m "Fixes #12"
   git push origin fix-issue-12
```
- This just an example, `Commit message` &  `Branch name` should be as Issue number.

5. **Open a PR (Pull request)**
   On GitHub, click “Compare & Pull Request” and ensure the PR message includes:
```sh
Fixes #12
```
> This will auto-link the `Issue` and close the issue when merged.
