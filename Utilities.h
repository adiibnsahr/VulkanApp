#pragma once

// Indices (locations) of Queue families (if they exist at all)
struct  QueueFamilyIndices
{
	int graphicsFamily = -1;
	
	// Check if queue families are valid
	bool isValid()
	{
		return graphicsFamily >= 0;
	}
};