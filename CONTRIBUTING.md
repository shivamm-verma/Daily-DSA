# How to create a fresh ISSUE?
> ![How to Create an Issue (1)](https://github.com/user-attachments/assets/a86a6435-1800-4003-bfc3-d04b8167fa59)
> Look at the steps above

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

# `GitHub Actions` scripts
Below are the workflow definitions, describing the purpose of each workflow in this repository:

- **`issue-create-automate-message.yml`** : Automatically posts a comment asking the issue author to wait until a maintainer reviews and assigns the issue. *(Triggered by GitHub Actions)*
- **`slash-startwork.yml`**: Allows repository maintainers to automatically assign issues and add labels using the `/startwork` command. For example, `/startwork 3` command will add the labels `Level-3`, `GsSOC`, and `Start Working`, assign the issue to its author, and post a message: "You can start working on this issue! ☺️"
- **`pr-create-automate-message.yml`** : Automatically comments on new pull requests, asking the PR author to wait for a maintainer’s review and assignment.
- **`pr-merge-automate-message.yml`** : When triggered, this assigns the merged PR to its author, applies the labels `PR Merged!🥳`, `GsSOC`, and `Level-{n}` (auto-detected from the linked issue), and comments to congratulate the contributor on their merged PR.