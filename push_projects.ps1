# Navigate to your ClassAssignments folder
cd "C:\\Users\\Dell User\\Downloads\\ClassAssignments"

# Define the list of zip files (you can add more if needed)
$projects = @("A03CPP (1).zip", "Assess3 (1).zip", "Assess4 (1).zip", "Assessment2.zip", `
              "Discussion_2.zip", "Gumball_Project.zip", "G_Project.zip", "Hemen_Babis_Lab1.zip", "Linked_List_Assignment.zip")

# Your GitHub repository URL (single repo for all projects)
$githubRepoUrl = "https://github.com/hemen-babis/class-assignments.git"

# Function to unzip and push each project to the same GitHub repository
foreach ($project in $projects) {
    # Unzip the project
    $projectName = [System.IO.Path]::GetFileNameWithoutExtension($project)
    $destinationFolder = "C:\\Users\\Dell User\\Downloads\\ClassAssignments\\$projectName"
    Write-Host "Unzipping $project to $destinationFolder"
    Expand-Archive -Path ".\\$project" -DestinationPath $destinationFolder -Force

    # Navigate to the project folder
    Set-Location $destinationFolder

    # Initialize a new Git repository (if not already initialized)
    git init

    # Remove existing remote if it exists to avoid the "remote already exists" error
    git remote remove origin

    # Add the remote GitHub repository (your main class-assignments repo)
    git remote add origin $githubRepoUrl

    # Pull any changes from the remote repository to avoid conflicts
    git pull origin main --rebase

    # Add all files to the repo
    git add .

    # Commit the files
    git commit -m "Initial commit for $projectName"

    # Push the project to the main branch
    git push -u origin main

    # Navigate back to the main directory for the next project
    Set-Location "C:\\Users\\Dell User\\Downloads\\ClassAssignments"
}

Write-Host "All projects have been pushed to the GitHub repository: $githubRepoUrl"
