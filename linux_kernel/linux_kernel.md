### Kernel Releases
- Release Candidate (RC) - used for testing new features in the mainline. Used to test for bugs and regressions.
- Stable - bug fix-only releases. Bug fixes made here are backported into the mainline. Updates released once a week on average, or on an as needed basis.
- Long term - stable releases selected for LT maintenance for providing ciritical bug fixes.

### Kernel Trees
- Mainline kernel tree - maintained by Linus Torvalds. Mainline kernels and RC releases are released here.
- Stable Tree - maintained by Greg Kroah-Hartman. Consists of stable release branches. Stable releases based on this tree.
- Linux-next Tree - maintained by Stephen Rothwell. Also known as Integration tree. Code from large number of subsystem trees gets pulled periodically and released for integration testing. Pulling changes from various trees catches merge conflicts between trees.

### Patch

Tags
- Signed-off-by
- Acked-by
- Reported-by
- Tested-by
- Reviewed-by
- Suggested-by
- Fixes

More 
- [PATCH] prefix used to indicate the email consists of a patch
- [PATCH RFC] - “Request for Comments”. Author is requesting comments on the patch.
- [PATCH v4] - patch is on the 4th version. Not unusual for a patch to go through multiple versions.
- Patch Version History - In the patch mail, under the “—“, include a short discription of changes made to the current version to give info to other people. This message is not added to the commit when it is merged into the source tree.
